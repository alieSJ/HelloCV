#include <opencv4/opencv2/imgcodecs.hpp>
#include <opencv4/opencv2/highgui.hpp>
#include <opencv4/opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

Mat frameHSV,maskred,maskred1,maskred2,maskgreen;
Mat imgGray,imgGaussBlur,imgCanny;

Scalar redlower1(0,43,46);
Scalar redupper1(10,255,255);
Scalar redlower2(170, 70, 70);  
Scalar redupper2(179, 255, 255);//红色的HSV是环形的

Scalar greenlower(71,147,110);
Scalar greenupper(106,255,255);

string getColor(Mat frame,Mat &maskred,Mat &maskred1,Mat &maskred2,Mat &maskgreen)//颜色处理
{
    cvtColor(frame,frameHSV,COLOR_BGR2HSV);
    inRange(frameHSV, redlower1, redupper1, maskred1);
    inRange(frameHSV, redlower2, redupper2, maskred2);
    bitwise_or(maskred1, maskred2, maskred);//合并两个红色
    inRange(frameHSV,greenlower,greenupper,maskgreen);  
    int redpoints = countNonZero(maskred);
    int greenpoints =countNonZero(maskgreen);
    if(redpoints>0&&greenpoints<100) return "red";
    else if(redpoints<100&&greenpoints>0) return "green"; 
    else return "None";
}

void showColor(Mat frame,Mat &frameOut)//显示文本
{
    string color =getColor(frame,maskred,maskred1,maskred2,maskgreen);
    if(color!="None")
    {
        putText(frameOut,color,Point(500,100),FONT_HERSHEY_DUPLEX,1.5,Scalar(255,0,0),3);
    }
}

void getContours(Mat mask,Mat &frameOut,Mat maskred,Mat maskgreen)
{
    Mat imgDil,imgErode;
    Mat kernel=getStructuringElement(MORPH_RECT,Size(3,3));
    erode(mask,imgErode,kernel ,Point(-1, -1), 1);
    dilate(imgErode,imgDil,kernel,Point(-1,-1),5);//进一步增大目标区域并连接断开的部分。增加迭代次数到 2 次

    vector<vector<Point>>contours;
    vector<Vec4i> hierarchy;

    findContours(imgDil,contours,hierarchy,RETR_EXTERNAL,CHAIN_APPROX_SIMPLE);
    for(int i=0;i<contours.size();i++)
    {
       int area =contourArea(contours[i]);
        
        vector<Rect> boundRect(contours.size());
        if(area>7000)
        {
            double peri = arcLength(contours[i], true);
            double circularity = (4 * CV_PI * area) / (peri * peri);
            
            if( circularity > 0.60)
            {
                boundRect[i]=boundingRect(contours[i]);
                rectangle(frameOut,boundRect[i].tl(),boundRect[i].br(),Scalar(255,0,0),5);
            }
       
        }
            
    }
}


int main()//视频读取与存储
{
    string path="resources/TrafficLight.mp4";
    VideoCapture cap(path);

    int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
    int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));

    VideoWriter writer;
    string Outpath="result.avi";
    int codec = VideoWriter::fourcc('M','J','P','G');
    double fps = cap.get(CAP_PROP_FPS);

    writer.open(Outpath,codec,fps,Size(frame_width,frame_height),true);

    Mat frame,frameOut;
    

    while(true)
    {
        cap.read(frame);
        frameOut = frame.clone();
        showColor(frame,frameOut);
        if(getColor(frame,maskred,maskred1,maskred2,maskgreen)=="red")
        {
            getContours(maskred,frameOut,maskred,maskgreen);
        }
        else if(getColor(frame,maskred,maskred1,maskred2,maskgreen)=="green")
        {
            getContours(maskgreen,frameOut,maskred,maskgreen);
        }
        
        writer.write(frameOut);

        imshow("Camera", frameOut);
        if (waitKey(20) == 27) break;
    }
    cap.release();
    writer.release();
}
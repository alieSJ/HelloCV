一.安装ROS2

思路：根据Ubuntu官网提供的ROS2安装教程和安装包逐步操作

1. 检查语言环境，确保支持utf-8编码

更新本地软件包索引，下载locales软件包![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760364901779-818d0490-d096-40ac-b703-148a9e45777b.png)

生成并配置所需的语言环境

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760365116979-3f7b670c-fc2a-48cb-9244-52db6b72460b.png)![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760365332370-aa329ef4-93e3-43a1-a5bb-e74bc7762eee.png)

2.设置来源

确保启用[Ubuntu Universe](https://help.ubuntu.com/community/Repositories/Ubuntu)仓库

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760365622573-b9c60d09-34be-4622-8da7-92ca75a77cef.png)

安装ros-apt-source软件包，便于配置ros2仓库

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760365784992-76041b90-07fe-4289-b888-a0d18efa70d3.png)![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760366426812-1e641a54-afcc-47f0-ad57-f1ccf5114eb4.png)

3.安装ROS2软件包

桌面安装

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760369816623-c60cd263-dd8a-4b8b-aa7f-0e90b53ccdd0.png)

开发工具安装

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760370998445-0d502014-b7f4-40f1-a7ab-6a2f12d73c52.png)

4.获取设置文件

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760371148088-6924a2a8-0c43-4630-8635-047717d00e0f.png)

source /opt/ros/humble/setup.bash

(永久设置环境

echo "source /opt/ros/humble/setup.bash" >> ~/.bashrc 

source ~/.bashrc  

）

二.OpenCV安装

主要根据网上教程安装，中途的错误依靠ai帮助解决

1.官网下载OpenCV4.5.5安装包![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760371650074-135396f2-17ff-47b7-9984-8b9b52335f59.png)

2.安装依赖的库

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760372138637-24b48ed5-fbc3-44a6-9929-f31e54a35d10.png)



![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760372631834-4f266156-40dc-4553-a364-cf723a33e5d7.png)

libjasper-dev文件始终无法安装，经搜索，得知在ubuntu22.04中以及不再使用此包，所以安装了其他包（最后一段安装命令)进行代替

3.创建新文件夹，在新文件夹下执行cmake

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760373089838-bcf3837f-0a0f-4e41-8e2c-938712f0e52f.png)

4.执行make指令

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760373204552-e9048cbc-1157-481a-a367-6fa58eeacc4f.png)

5.执行install指令（安装步骤完成）![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760375077648-9f17fa15-e84a-44e8-b00d-95fe0dcef93a.png)

6.配置

将OpenCV的库添加到路径，从而可以让系统找到

打开文件![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760375142827-23047c03-9a16-4212-b1af-fc9a874aad01.png)

在文件末尾添加/usr/local/lib，保存退出，生效配置文件![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760375146175-e74e14c1-b322-48da-bc9e-660c0d5c9e42.png)

配置bash.bashrc文件，在末尾追加PKG_CONFIG_PATH=$PKG_CONFIG_PATH:/usr/local/lib/pkgconfig  



export PKG_CONFIG_PATH，保存退出

设置过程中出现gedit元数据警告，安装了dbus-x11包后仍然无法解决warning，在确认不影响opencv配置后，忽略警告![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760375966478-ef3482cf-822f-4989-a47b-d3b9a9e349d1.png)

执行命令使配置生效

source /etc/bash.bashrc

更新

sudo updatedb

终端显示不存在updatedb命令，通过下载mlocate包解决



测试过程中发现有问题，无法正常打开摄像头，根据终端提供的报错信息和解决方法If you are on Ubuntu or Debian, install libgtk2.0-dev and pkg-config, then re-run cmake or configure script in function 'cvShowImage'，结合ai重新配置和编译opencv如下：

sudo apt install libgtk2.0-dev pkg-config

# 进入 OpenCV 构建目录

cd ~/opencv-4.5.5/my_build_dir

# 清除之前的配置

rm -rf *

# 重新运行 cmake 配置

cmake ..

# 重新编译

make -j4

# 安装

sudo make install

sudo ldconfig

# 测试 OpenCV 是否正常工作

cd ~/opencv-4.5.5/samples/cpp/example_cmake/build

./opencv_example



重新配置后测试正常

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760379396076-d990218b-f414-442c-b377-87b898628ac5.png)



三.安装vs code

1.官网下载安装包 

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760415217296-743f7ce1-c781-4f60-9913-4879ef6fc863.png)

2.通过终端命令安装

先找到.deb文件位置，点击在终端中打开![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760415336904-e99cd54e-650a-4f72-b386-e4cfa25c9b51.png)

输入

sudo - 使用管理员权限，dpkg - 包管理 ，-i - 安装软件包

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760415460944-c7c45bf3-0e7b-4d40-b47c-fbaf0411e1e6.png)

3.安装完毕后输入code，即可打开scode

4.配置code

安装所需拓展

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760416004903-a46ce322-6088-4d2d-b697-d120f86b9bb9.png)

创建project文件夹，用以存放项目文件

再在project下创建hellocv文件夹，在hellocv下打开vscode，作为工作区使用

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760416183073-8190192f-5361-4140-b382-d13df20a00f0.png)

在hellocv下创建所需的配置文件

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760418490812-b4873766-96b0-4bf5-bc66-7ca553ee9531.png)

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760418506602-f5f6cb10-01f2-40e3-b38a-45759e7ba15d.png)



测试结果

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760421761941-a91010e8-6ea3-4d1c-b2a6-6a0ed4ae1f66.png)



四.Git配置

下载Git

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760421926533-ebdc88e9-9f26-4287-ac0a-eebd5a335726.png)

配置用户名和邮箱

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760422030973-1ab4afe9-e953-4cfa-9e5d-772a7ee2f906.png)

生成ssh密钥

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760422081248-d6467626-d687-4eae-88ae-e6515b91f4fe.png)

查看密钥

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760422107402-6a338bbd-5b5f-4897-945c-847b106473f9.png)

在github上配置密钥

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760422178943-792266b9-87c7-4592-ad16-433a811316dc.png)

之后可以通过git clone操作在通过远程库生成本地库，然后就可以做操作了

比如上传文件，将远程库内容连接到本地库等

![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760437208152-88a211a7-4201-4c14-ae10-8c885e4cfe1d.png)![](https://cdn.nlark.com/yuque/0/2025/png/61471817/1760437211146-9472ecae-699c-47b0-b200-4e504506c944.png)


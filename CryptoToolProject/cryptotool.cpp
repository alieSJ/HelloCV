#include<iostream>
#include<cstring>
#include<fstream>
#include <limits>

using namespace std;
class FileHandler;
class Menu;

void clearInputBuffer() {
    if (cin.fail() || cin.peek() == '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

class Crypto{
    friend Menu;
    public:
    void encryptCaesar(string &plaintext,string &ciphertext,int key);
    void decryptCaesar(string &plaintext,string &ciphertext,int key);
    void XOR(string &input,string &output,int key);
};

void Crypto::encryptCaesar(string &plaintext,string &ciphertext,int key)
{   int n=plaintext.length();
    ciphertext.resize(n);
    for (int i=0;i<n;i++)
    {   if(plaintext[i]<='Z'&&plaintext[i]>='A')
        {
         ciphertext[i]=('A'+(plaintext[i]-'A'+key%26)%26);
        }
        else if(plaintext[i]<='z'&&plaintext[i]>='a')
        {
         ciphertext[i]=('a'+(plaintext[i]-'a'+key%26)%26);
        }
        else ciphertext[i]=plaintext[i];
    }
}

void Crypto::decryptCaesar(string &plaintext,string &ciphertext,int key)
{
    int n=ciphertext.length();
    plaintext.resize(n);
    for (int i=0;i<n;i++)
    {
        if(ciphertext[i]<='Z'&&ciphertext[i]>='A')
        {
            plaintext[i]=('A'+(ciphertext[i]+(26-key%26)-'A')%26);

        }
        else if(ciphertext[i]<='z'&&ciphertext[i]>='a')
        {
            plaintext[i]=('a'+(ciphertext[i]+(26-key%26)-'a')%26);
        }
        else plaintext[i]=ciphertext[i];
    }
}

void Crypto::XOR(string &input,string &output,int key)
{
    output.clear();
    for(char x:input)
    {  
        output+=char(x^(key%256));
    }
}

class FileHandler{
    friend Menu;
    friend Crypto;
    public:
    void Readfile(const string source_file,string &content);
    void Writefile(const string new_file,const string content);
};

void FileHandler::Readfile(const string source_file,string &content)
{
    ifstream file (source_file,ios::in | ios::binary);
    if(!file.is_open()){
        cout<<"erorr,cannot open "<< source_file <<endl;
        file.close();
        content.clear();
    }
    else{
        content.clear();
        string line;
        while(getline(file,line)){
            content+=line;
            content+='\n';
        }
        file.close();
    }
}

void FileHandler::Writefile(const string new_file,const string content){
    ofstream file (new_file, ios::out | ios::binary);
    if (!file.is_open()) {
        cout << "错误: 无法创建或打开文件 "<< new_file << endl;
    }
    else{
        file <<content;
    }
    file.close();
}

class Menu{
    public:
    void CompositeCatalog();
    void AlgorithmCatalog();
    int Getin(int &getin);
    string SwitchAlgorithm(int getin);
    void TextEncryptmode();
    void TextDecryptmode();
    void FileEncryptmode();
    void FileDecryptmode();
    void SwitchCompositeCatalog(int getin);
    void run();
    private:
    Crypto crypto;
    FileHandler fileHandler;
};

void Menu::CompositeCatalog()
{
    cout<<"Encryption and Decryption Tool"<<endl
        <<"1.Encrypt text"<<endl
        <<"2.Decrypt text"<<endl
        <<"3.Encrypt file"<<endl
        <<"4.Decrypt file"<<endl
        <<"0.exit"<<endl
        <<"please put your choice"<<endl;
}

void Menu::AlgorithmCatalog(){
    cout<<"Choose the algorithm"<<endl
        <<"1.Caesar"<<endl
        <<"2.XOR"<<endl;
}

int Menu::Getin(int &getin)
{
    int input;
    if (cin >> input) {
        getin = input;
        return input;
    } else {
        cout << "无效输入! 请输入一个整数。" << endl;
        return -1;
    }
}

void Menu::SwitchCompositeCatalog(int getin){
    switch(getin){
        case 1:
            TextEncryptmode();
            break;
        case 2:
            TextDecryptmode();
            break;
        case 3:
            FileEncryptmode();
            break;
        case 4:
            FileDecryptmode();
            break;
        case 0:
            cout << "bye" << endl;
            break;
        default:
            cout << "erorr,input again" << endl;
            break;
    }
}

string Menu::SwitchAlgorithm(int getin){
    AlgorithmCatalog();
    if(getin==1) return "Caesar";
    if(getin==2) return "XOR"; 
    return "";
}

void Menu::TextEncryptmode()
{
    string plaintext;
    string ciphertext;
    int choice;
    int key =0;
    ciphertext.clear();

    cout << "Text Encrtpt Mode"<<endl;

    AlgorithmCatalog();
    Getin(choice);
    string algorithm=SwitchAlgorithm(choice);
    
    cout<<"please enter the text"<<endl;
    clearInputBuffer();
    getline(cin,plaintext);

    cout<<"please enter the key"<<endl;
    cin>>key;

    if(algorithm=="Caesar")
    {
        crypto.encryptCaesar(plaintext,ciphertext,key);
    }
    else if(algorithm=="XOR")
    {
        crypto.XOR(plaintext, ciphertext, key);
    }

    cout<<"Plaintext:  " << plaintext << endl
        << "Key:        " << key << endl
        << "Ciphertext: " << ciphertext << endl;
}

void Menu::TextDecryptmode()
{
    string plaintext;
    string ciphertext;
    int choice;
    int key =0;
    plaintext.clear();

    cout << "Text Encrtpt Mode"<<endl;

    AlgorithmCatalog();
    Getin(choice);
    string algorithm=SwitchAlgorithm(choice);
    
    cout<<"please enter the text"<<endl;
    clearInputBuffer();
    getline(cin,ciphertext);

    cout<<"please enter the key"<<endl;
    cin>>key;

    if(algorithm=="Caesar")
    {
        crypto.decryptCaesar(plaintext,ciphertext,key);
    }
    else if(algorithm=="XOR")
    {
        crypto.XOR(ciphertext, plaintext, key);
    }

    cout<<"Ciphertext:  " << ciphertext << endl
        << "Key:        " << key << endl
        << "Plaintext: " << plaintext << endl;
}

void Menu::FileEncryptmode()
{
    string content,encryptcontent;
    string sourcefilename;
    string newfilename;
    int choice;
    int key =0;
    encryptcontent.clear();

    cout << "Text Encrtpt Mode"<<endl;

    AlgorithmCatalog();
    Getin(choice);
    string algorithm=SwitchAlgorithm(choice);
    
    cout<<"please enter the filename"<<endl;
    clearInputBuffer();
    getline(cin,sourcefilename);

    fileHandler.Readfile(sourcefilename, content);
    
    cout<<"please enter the key"<<endl;
    cin>>key;

    if(algorithm=="Caesar")
    {
        crypto.encryptCaesar(content,encryptcontent,key);
    }
    else if(algorithm=="XOR")
    {
        crypto.XOR(content,encryptcontent, key);
    }
    
    cout<<"please enter the filename which you want the cryptied text in"<<endl;
    clearInputBuffer();
    getline(cin,newfilename);
    fileHandler.Writefile(newfilename, encryptcontent);
}

void Menu::FileDecryptmode()
{
    string content,decryptcontent;
    string sourcefilename;
    string newfilename;
    int choice;
    int key =0;
    
    decryptcontent.clear();

    cout << "Text Encrtpt Mode"<<endl;

    AlgorithmCatalog();
    Getin(choice);
    string algorithm=SwitchAlgorithm(choice);
    
    cout<<"please enter the filename"<<endl;
    clearInputBuffer();
    getline(cin,sourcefilename);

    fileHandler.Readfile(sourcefilename, content);
    
    cout<<"please enter the key"<<endl;
    cin>>key;

    if(algorithm=="Caesar")
    {
        crypto.decryptCaesar(decryptcontent,content,key);
    }
    else if(algorithm=="XOR")
    {
        crypto.XOR(content,decryptcontent, key);
    }
    
    cout<<"please enter the filename which you want the cryptied text in"<<endl;
    clearInputBuffer();
    getline(cin,newfilename);
    fileHandler.Writefile(newfilename, decryptcontent);
}

void Menu::run()
{
    int choice=-1;
    while(choice!=0)
    {
        CompositeCatalog();
        choice = Getin(choice);
        SwitchCompositeCatalog(choice);
    }
}
int main()
{
   Menu start;
   start.run();
   return 0;
}

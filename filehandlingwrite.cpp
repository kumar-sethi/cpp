#include<fstream>
#include<iostream>
int main()
{
    using namespace std;

   //Creating File object to output it in kumar.txt
    ofstream ofs;
    ofs.open("kumar.txt", ios::out); // by default, mode is ios::out

    if(ofs.is_open())
    {
        ofs << "Writing into my first file"<<endl;
        ofs << "Hi, My name is Kumar Sethi\n";
        ofs << "-------------------"<<endl;
        ofs.close();
    }
    ofs.open("kumar.txt", ios::app);// this will append the file
    if(ofs.is_open())
    {
        ofs << "Last line"<<endl;
        ofs.close();
    }
}

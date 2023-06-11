#include<fstream>
#include<iostream>
int main()
{
    using namespace std;

    ifstream ifs;
    ifs.open("kumar.txt"); // by default, mode is ios::in

    string strRead;
    if(ifs.is_open())
    {
        // while(!ifs.eof()){----- This will also work
        //     getline(ifs, strRead);
        //     cout<<strRead<<endl;
        // }
        while(getline(ifs, strRead)){
            cout<<strRead<<endl;
        }
        ifs.close();
    }
}

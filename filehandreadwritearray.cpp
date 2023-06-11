#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{

    //Writing and reading arr in a file
    vector<int> arr{6,3,9,-4,115};
    fstream fstr;
    fstr.open("kumarArray.txt", ios::out);
    if(fstr.is_open())
    {
        for(int i=0; i<arr.size(); i++)
            fstr<<arr[i];
        fstr.close();
    }

    fstr.open("kumarArray.txt", ios::in);
    int num;
    if(fstr.is_open())
    {
        while(!fstr.eof()){
            fstr>>num;
            cout<<num;
        }
        fstr.close();
    }
}
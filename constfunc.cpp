#include <iostream>
#include<vector>
using namespace std;

class Sample
{
    public:

    void process()
    {
        cout<<"Non Const"<<endl;
    }
    
    void process() const
    {
        cout<<"Const"<<endl;
    }
};

int main()
{
    Sample s;
    s.process();

    const Sample* ptr = &s;
    ptr->process();

    const auto ptr2 = &s;
    ptr2->process();
}
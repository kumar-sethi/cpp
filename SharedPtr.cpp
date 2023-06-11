#include<iostream>

using namespace std;

template <typename T>
class SharedPtr
{
    T* m_ptr;
    unsigned short* m_shRefCount;
public:
    SharedPtr(T* ptr = nullptr):m_ptr(new T), m_shRefCount(new short(1)){}
    


};



int main()
{

    SharedPtr<int> obj{new int};
    


}
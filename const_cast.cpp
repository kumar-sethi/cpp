#include<iostream>
using namespace std;

main(void)
{
    int val = 26;
    const int* ptr = &val;
    int * pVal = const_cast<int*> (ptr);
    *pVal = 45;
    cout<<*pVal;
    return 0;
} //

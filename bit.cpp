#include <iostream>
#include <conio.h>
using namespace std;


void countsetbits(int num){
    int count = 0;
    while(num){
        count += (num & 1);
        num = num>>1;
    }
    cout<<count;
}
// 1010 for 10 

void setabit(int num, int bitpos){
    num = num | (1 << bitpos);
    cout<<"Num after setting"<<bitpos<<
    "th bit->"<<num<<endl;
}

void unsetabit(int num, int bitpos){
    //num = (num << bitpos);
    num = num & ~(1<<bitpos);
    cout<<"Num after unsetting"<<bitpos<<
    "th bit->"<<num<<endl;
}

void ispow2(int n){
    if( (n&(n-1)) == 0)
        cout<<"Yes it is Power of 2"<<endl;
    else
        cout<<"Not Power of 2"<<endl;

}

main(){
    int a = 5;
    cout<<a<<endl;
    a = a<<1;
    cout<<a<<endl;
    countsetbits(10);

    int n = 3, bit=2;
    cout<<endl<<"Num before setting"<<bit<<
    "th bit->"<<n<<endl;
    setabit(n, 2);
    unsetabit(n, 2);

    ispow2(8);

}
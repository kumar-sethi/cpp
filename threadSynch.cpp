#include<iostream>
#include<thread>
#include<mutex>
using namespace std;
long long bankbal = 0;
mutex m;
void addMoney(long long val){
    m.lock();
    bankbal += val;
    m.unlock();
}
main(){

    thread t1(addMoney, 100);
    thread t2(addMoney, 200);

    t1.join();
    t2.join();

    cout<<"Final: "<<bankbal<<endl;
    
}
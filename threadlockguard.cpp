#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;
mutex m1;
int buffer = 0;

void task(const char* T, int val){
    lock_guard<mutex> lk(m1);
    for (int i = 0; i < val; i++)
        cout<<T<<" : "<<++buffer<<endl;
}

main(){
    thread t1(task, "T1", 10);
    thread t2(task, "T2", 10);
    t1.join();
    t2.join();
}
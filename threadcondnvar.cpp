#include<iostream>
using namespace std;
#include<mutex>
#include<condition_variable>
#include<thread>

mutex m2;
condition_variable cond;
int count = 0;

void odd(const char* T, int val){
    while (val>=count)
    {
        unique_lock<mutex> ul(m2);
        cond.wait(ul, []() { return count%2==1;});
        if(count<=val)
            cout<<T<<" Odd : "<<count++<<endl;
        ul.unlock();
        cond.notify_all();
    }
}

void even(const char* T, int val){
    while (val>=count)
    {
        unique_lock<mutex> ul(m2);
        cond.wait(ul, []() { return count%2==0;});
        cout<<T<<" Even : "<<count++<<endl;
        ul.unlock();
        cond.notify_all();
    }
}

main(){
    thread t1(odd, "T1", 10);
    thread t2(even, "T2", 10);
    t1.join();
    t2.join();   
}
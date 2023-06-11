#include<iostream>
#include<condition_variable>
#include<thread>
#include<mutex>
#include<queue>
using namespace std;

deque<int> dq;
mutex m1;
condition_variable cond;
#define MAX_BUFFER 50
void Producer(int value)
{
    while(value)
    {
        unique_lock<mutex> uqLock(m1);
        cond.wait(uqLock, [](){
            return (dq.size()<MAX_BUFFER);
        });
        dq.push_back(value);
        cout<<"Produced: "<<value<<endl;
        value--;
        cond.notify_one();
    }
}

void Consumer()
{
    while(true)
    {
        unique_lock<mutex> uqLock(m1);
        cond.wait(uqLock, [](){
            return dq.size()>0;
        });
        int res = dq.back();
        dq.pop_back();
        cout<<"Consumed: "<<res<<endl;
        cond.notify_one();
    }
}



int main()
{
    thread t1(Producer, 100);
    thread t2(Consumer);
t1.join(); t2.join();

}
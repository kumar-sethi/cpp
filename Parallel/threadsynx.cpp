#include<iostream>
#include<list>
#include<thread>
#include<mutex>
#include<exception>
using namespace std;

list<int> g_Data;
const int SIZE = 10000;
mutex g_Mutex;
void Download(){
    for (size_t i = 0; i < SIZE; i++){
        //g_Mutex.lock();
        lock_guard<mutex> mtx(g_Mutex); //local object gets destroys at end of block 
                                        // whose destructor will automtcly release lock
        g_Data.push_back(i);
        if(i==5000)
            return; // Deadlock as other thread will keep on waiting for this thread to release lock
        //g_Mutex.unlock();
    }
}
// Race condition: two threads race with eack other to access the data
void Download2(){
    for (size_t i = 0; i < SIZE; i++){
        //g_Mutex.lock();
        lock_guard<mutex> mtx(g_Mutex);
        g_Data.push_back(i);
        //g_Mutex.unlock();
    }
}

int main(int argc, char const *argv[])
{
    thread th1(Download);
    thread th2(Download2);

    th1.join();
    th2.join();

    cout<<"Size :"<<g_Data.size()<<endl;

    return 0;
}

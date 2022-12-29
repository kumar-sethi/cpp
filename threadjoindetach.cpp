#include<iostream>
#include<thread>
#include<mutex>
using namespace std;

void run(int count){
    while(count --> 0)
        cout<<"Running"<<endl;
    std::this_thread::
    sleep_for(chrono::seconds(3));

}

main(){

    thread t1(run, 10);
    cout<<"main before"<<endl;
    std::this_thread::
    sleep_for(chrono::seconds(3));
    t1.join(); //wait for thread t1 to execute first
    //t1.join(); //double join will result into program termination
    if(t1.joinable())
        t1.join();
    cout<<"main after"<<endl;
    
}
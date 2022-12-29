#include<thread>
#include<iostream>
using namespace std;

void cpu_waster(){
    cout<<"CPU Waster Process Id: "<<getpid()<<endl;
    cout<<"CPU Waster Thread Id: "<<this_thread::get_id()<<endl;
    while(true) continue;
}

main(){
    cout<<"Main Process Id: "<<getpid()<<endl;
    cout<<"Main Thread Id: "<<this_thread::get_id()<<endl;
    thread t1(cpu_waster);
    thread t2(cpu_waster);

    while (true)
    {
        this_thread::sleep_for(chrono::seconds(1));
    }
    
}
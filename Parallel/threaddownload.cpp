#include<iostream>
#include<list>
#include<thread>
using namespace std;

list<int> g_Data;
const int SIZE = 5000000;

void Download(std::string &filename){
    cout<<"[Downloader] Started Downloading... File:"<<filename<<endl;
    for (size_t i = 0; i < SIZE; i++)
    {
        g_Data.push_back(i);
    }
    cout<<"[Downloader] Finished Download... "<<endl;
}

int main(){

    cout<<"[Main]User started an operation"<<endl;
    //Download();
    std::string file{"cppcast.mp4"};
    thread thDownloader(Download, ref(file));    
    //thDownloader.detach();// Dont want to wait for thread to complete
                            // A detach thread cannot be joined
    cout<<"[Main]User started another operation"<<endl; // Not blocked by downloader thread
    if(thDownloader.joinable())
        thDownloader.join(); // Main thread waits downloader thread to complete
                            // generates std::system_error at runtime if we call join() on detached thread
    //esystem("pause");
}
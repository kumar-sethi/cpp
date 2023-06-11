#include <iostream>
#include<mutex>
#include<thread>
using namespace std;


class MyApp{

    private:
        static MyApp * m_pInstance;
        static mutex objMutex;
        MyApp(const string name): m_strName(name){}
        MyApp(const MyApp&) = delete;
        MyApp& operator=(const MyApp&) = delete;
    public:
        static MyApp* getInstance(string name)
        {
            
            lock_guard<mutex> objLockGuard(objMutex);//RAII
            //objMutex.lock();
            // Start lock lga denge
            if(!m_pInstance)
                m_pInstance = new MyApp(name);
            //objMutex.unlock();
            //lock release 
            return m_pInstance;
        }

        void callable(){
            puts("m_pInstance is Live");
        }
        string m_strName;
};

MyApp* MyApp::m_pInstance{nullptr};
mutex MyApp::objMutex;

void ThreadFoo(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    MyApp* MyApp = MyApp::getInstance("FOO");
    std::cout << MyApp->m_strName << "\n";
}

void ThreadBar(){
    // Following code emulates slow initialization.
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    MyApp* MyApp = MyApp::getInstance("BAR");
    std::cout << MyApp->m_strName << "\n";
}

int main()
{

    thread t1(ThreadFoo);
    thread t2(ThreadBar);
    t1.join();
    t2.join();

    //MyApp *obj2 = MyApp::getInstance("Sethi");
    //cout<<obj2->m_strName;
    //obj2->callable();

}
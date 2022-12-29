#include<iostream>
#include<string>
#include<vector>

using namespace std;
void message(const string & s) {
    puts(s.c_str());
    fflush(stdout);
}
void disp_t(vector<string> &v){
    if(v.empty())
        puts("[empty]");
    else{
        for (string s:v)
            printf("%s ", s.c_str());
        puts("");        
    }
    fflush(stdout);
}

template<typename T>
void swap(T& a, T& b){
    message("Swapping..");
    T c = move(a);
    a = move(b);
    b = c;

}

main(){

    vector<string> v1 = {"one", "two", "three", "four", "five"};
    vector<string> v2 = {"six", "seven", "eight", "nine", "ten"};

    disp_t(v1);
    disp_t(v2);

    //v1 = move(v2);
    //auto v3 = move(v2);

    ::swap(v1,v2);  // scope resolution makes sure we are using our class's swap func i.e. current context func
                    // not the swap one that is in std:: library
    
    disp_t(v1);
    disp_t(v2);
/* 
    disp_t(v1);
    disp_t(v2);
    disp_t(v3); */
 }
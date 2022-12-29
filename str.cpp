#include<iostream>

using namespace std;

string& retStr(){
    string str = "KSETHI";
    return str;
}

main(){
    string& str = retStr();
    cout<<&str;
}

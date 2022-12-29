#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int a = 7;
    int b = 30;
    int div =2;
    auto c = [div](int a, int y){
        return (a+y)/div; 
    };
    cout<<c(a,b)<<endl<<"Printing Vector values:- \n";

    vector<int> vec{1,2,3,4,5,6};
    for_each(vec.begin(), vec.end(), 
            [](int val) {
            cout<<val<<endl;
        }
    );

}
#include<iostream>
#include<bits/stdc++.h>
//#include<string>
using namespace std;

main(){
vector<string> myvec {"Ab", "cd", "ef", "gki gdkj"};
//vector<int> myvec {1, 2,3,4,5,6};
auto it = find(myvec.begin(), myvec.end(), "c d");

if(it!=myvec.end())
    cout<<"PResent"<<endl;
else
    cout<<"Absent"<<endl;


vector<string>::iterator itr;

for(itr= myvec.begin(); itr!= myvec.end(); itr++){
    cout<<*itr<<endl;
}

}

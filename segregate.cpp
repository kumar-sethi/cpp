#include<iostream>
using namespace std;

main(){

    int arr[] = {1,0,0,0,1,1,1,0,1,1,0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count =0;
    for(int i=0;i<n;i++){
            cout<<arr[i];
    }
    cout<<endl;
/*     for(int i=0;i<n;i++){
        if(arr[i] == 0){
            cout<<"0";
            count++;
        }
    }
    for(int i=0; i<n-count; i++)
        cout<<"1"; */

    int i=0, j=n-1;
    while(i<j){
        if(arr[i]==1){
            swap(arr[i], arr[j]);
            j--;
        }
        else{
            i++;
        }
    }
    for(int i=0;i<n;i++){
            cout<<arr[i];
    }

}
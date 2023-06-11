#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int findIndex(vector<int> arr, int element){

	//sort(arr.begin(), arr.end());
	for(int i=0; i<arr.size(); i++){
		if(element==arr[i])
			return i;
	}
}
//O(nlogn)

main(){
    vector<int> arr{1, 30, 11, 15, 20, 60, 36, 26, 70, 5, 10};
    cout<<findIndex(arr, 15);
    
}
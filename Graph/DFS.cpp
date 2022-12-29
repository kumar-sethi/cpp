#include<iostream>
#include <stack>
using namespace std;
stack<int> st;
int visited[7] = {0};

void DFS(int G[][7], int start, int size){

    st.push(start);
    visited[start] = 1;

    int u = st.top();
    for (size_t v = 0; v < size; v++)
    {
        if(G[u][v]==1 && visited[v]==0){
            visited[v]=1;  cout<<"\t"<<v<<"\t"; DFS(G, v, size);
        }
    }
    st.pop();
}

main(){
    int arr[7][7] = {
        {0,0,0,0,0,0,0},
        {0,0,1,1,0,0,0},
        {0,1,0,0,1,0,0},
        {0,1,0,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0},
        {0,0,0,0,1,0,0}
    };
    int start = 4;
    cout<<"DFS:"<<"\t"<<start<<"\t";
    DFS(arr,start,7);
}

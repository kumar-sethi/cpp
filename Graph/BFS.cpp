#include<iostream>
#include <queue>
using namespace std;
void BFS(int G[][7], int start, int size){

    int visited[size] = {0};
    queue<int> que;
    que.push(start);
    visited[start] = 1;
    std::cout<<"BFS: "<<start<<"\t";
    
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (size_t v = 0; v < size; v++)
        {
            if(G[u][v]!=0 && visited[v]!=1){
                visited[v]=1; que.push(v); cout<<v<<"\t";
            }
        }
    }
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
    BFS(arr,1,7);
}

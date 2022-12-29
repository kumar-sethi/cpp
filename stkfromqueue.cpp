#include<iostream>
#include<queue>
using namespace std;

struct stack{
    queue<int> q1;
    queue<int> q2;
    int len;
    stack(){
        len = 0;
    }
    void push(int data){
        q2.push(data);
        len++;
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1,q2);
    }

    void pop(){
        //cout<<q1.front()<<endl;
        q1.pop();
        len--;
    }

    int top(){
        if(!q1.empty())
            return q1.front();
        return 0;
    }
};

main(){

stack s;

s.push(1);
s.push(2);
s.push(3);

while(s.len>0){
    cout<<s.top();
    s.pop();
}


}

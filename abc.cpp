#include<iostream>
#include<stack>
using namespace std;


struct Queue{

    stack<int> s1,s2;
    void enque(int v){

        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(v);
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
    }

    int deque(){
  
        int x = s1.top();
        s1.pop();
        return x;
    }

};
#define OP 
#define CL ')'||']'||'}'
bool checkBalance(char a, char b){
    return { (a == '(' && b ==')')
            || (a == '[' && b ==']') 
            || (a == '{' && b =='}') };
}
void balanceParanth(string s){
    stack<char> st;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '('||
            s[i] == '['||
            s[i] == '{')
            st.push(s[i]);
        else{
            if(st.empty()){ // If empty
               cout<<"Not Balanced"<<endl;
               return;
            }
            else{
                bool bBal = checkBalance(st.top(), s[i]);
                if(bBal)
                    st.pop();
                else{
                    cout<<"Not Balanced"<<endl;;
                    return;
                }
            }
        }
    }
    if(st.empty())
        cout<<"Balanced"<<endl;
    else
        cout<<"Not Balanced"<<endl;

}
main(){
/*     Queue q;
    q.enque(1);
    q.enque(2);
    q.enque(3);
 //   cout<<q.deque()<<endl;
 //   cout<<q.deque()<<endl;
    q.enque(4);
    q.enque(5);
    q.enque(6);
    //cout<<q.deque()<<endl;

 //   q.printq();
 */
    string s = "({})";
    string s1 = "((())";
    string s2 = "([)}";
    string s3 = "{}([()])";
    string s4 = "(()))";
    balanceParanth(s4);

}
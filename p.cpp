#include<bits/stdc++.h>
using namespace std;
main()
{

    string str = "()]";
    stack<char> st;

    if(str.empty())
        return 0;

    if(str[0] == ']' ||
        str[0] == ')' ||
        str[0] == '}'){
            cout<<"Invalid";
            return 0;
        }

    for(int i=0; i<str.size(); i++){

        if(str[i] == '[' || str[i] == '{' || str[i] == '(')
            st.push(str[i]);

        else if (
                str[i] == ']' && !st.empty() && st.top() == '[' 
                || str[i] == ')' && !st.empty() && st.top() == '(' 
                || str[i] == '}' && !st.empty() && st.top() == '{' )     
                    st.pop();
        else
            st.push(str[i]);
    }
    if(st.empty())
        cout<<"Valid";
    else
        cout<<"InValid";
}
#include<iostream>
#include<unordered_map>
using namespace std;

int lengthSubStr(string str)
{
    unordered_map<char, int> mp;
    
    for(int i=0; i<str.size(); i++)
    {
        mp[str[i]] = i;
    } 
}


int main()
{

}
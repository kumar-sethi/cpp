#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

main(){

    vector<int> vec = {5,4, 5,1,2,3};
    //vec[9] = 6; wont affect vec
    for(auto it :vec)
        cout<<" "<<it<<endl;

    sort(begin(vec), end(vec));
    // begin end sort and finf comes in <algorithm>
    for(auto it = begin(vec); it!= end(vec); it++)
        cout << " "<<*it<<endl;

    cout <<"Count:"<< count(begin(vec), end(vec), 5);

    string s = "Kumar", kk;
    string s2 = "Sethi";
    cout<<s2+ s.substr(1, 4) <<endl;
    cout<<s.substr(1, 4)<<endl;
    if(s=="kumar")
        cout<<"Equal";
    else
        cout<<"Not";

    string name;
    cout<<"Who are you?";
    //cin>>name;

    string greet = "Hello, "+name;
    if(name == "Sethi")
        greet += ", You're actualyy writing code.";

    int len = greet.length(); 
    cout<<"\"" + greet + "\" is "<<len<<" chars long.\n";

    string beg = greet.substr(greet.find(' ') + 1);
    cout<<beg<<'\n';
    if(beg == name)
    {
        cout<<"Expected result";
    }
    else
        cout<<"Not Exp";

    cout<<endl<<"Enter : ";
    cin.ignore();
    //getline(cin, kk);
    cout<<kk;

    //j'getch();
    //return 0;
}
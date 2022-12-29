#include <iostream>
#include <vector>
using namespace std;
 
 class c1{

     int a;
     const char* b = "";

     public:
        c1(int x, char * y) : a(x), b(y){cout<<"Initialiser List cons"<<endl;};
        c1() {cout<<"Default cons";};

        void setA(const int a){
            this->a = a;
        }
         int getA() {
            puts("normal wala");
            return a;
        } 
        int getA() const {
            cout<<"const wala"<<endl;
            return a;
        }
        //Const func can be called by normal/const obj 
        //but NOn const only called by non const obj.
        
 };

 main(){

    /* Const Qualified func and objects understanding
    c1 obj(3,"fre");
    c1 ob2;
    const c1 ob38;
//     ob2.setA(43);
    cout<<ob2.getA()<<endl;
    cout<<ob38.getA()<<endl;
*/
    c1 o1;
    o1.setA(99);
    cout<<"Value: "<<o1.getA()<<endl;
    c1 o2 = o1;
    cout<<"Value: O2 -> "<<o2.getA()<<endl;
    
    o1.setA(72);
    o2 = o1;
    cout<<"Value: ->>  "<<o1.getA()<<endl;
    cout<<"After Coppy Assignment Value: "<<o2.getA()<<endl;



 }

/*      for(int i=1; i<=1; i++){
        int n;
        cin >> n;
        vector<string> names(n);
        for(int j=0; j<n; j++){
            string input;
            cin.ignore();
            getline(cin, input);
            names.push_back(input);
        }
        for(auto it : names)
            cout<<endl<<it<<endl;
            
        //int totalMoney = calcMoney(names);
        //money.push_back(totalMoney);
    }

 */
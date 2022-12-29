#include<iostream>
#include<map>
using namespace std;

class Emp{

    public:
        int EmpId;

        string name;

/*     public:

        Emp(int val, string nstr): EmpId(val), name(nstr){}

         bool operator<(const Emp& obj){

            if(this->EmpId < obj.EmpId )
                return true;

        } */

};


main(){

    map<Emp, int> mymap;

    mymap.insert(std::make_pair<Emp, int>(Emp(1, "Kumar"), 29));
    mymap.insert(std::make_pair<Emp, int>(Emp(2, "Ishant"), 23));
    mymap.insert(std::make_pair<Emp, int>(Emp(3, "Paras"), 24));
    mymap.insert(std::make_pair<Emp, int>(Emp(4, "Sethi"), 26));

    map<Emp, int>::iterator it = mymap.begin();

    for(it; it!=mymap.end(); it++)
    {
        cout<<it->first.EmpId<<"   "<<it->second<<endl;
    }

}
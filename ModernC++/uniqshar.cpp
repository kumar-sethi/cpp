#include <iostream>
#include<memory>
using namespace std;
class Employee;
class Project{
    public:
    //Employee* m_emp;
    shared_ptr<Employee> m_emp;
    Project(){
        cout<<"Project"<<endl;
    }
    ~Project(){
        cout<<"~Project"<<endl;
    }
};

class Employee{
    public:
    //Project* m_prj;
    weak_ptr<Project> m_prj;
    Employee(){
        cout<<"Employee"<<endl;
    }
    ~Employee(){
        cout<<"~Employee"<<endl;
    }
};

int main(){
   
   /*
    unique_ptr<int> p{new int(5)};
    cout<<*p.get();
*/

    // Circular References
    shared_ptr<Employee> emp{new Employee{}};
    shared_ptr<Project> prj{new Project{}};
    
    emp->m_prj = prj;
    prj->m_emp = emp;

    // Memory leak happens as both are in dependant on each other

    //delete prj;
    //delete emp;

    return 0;
}
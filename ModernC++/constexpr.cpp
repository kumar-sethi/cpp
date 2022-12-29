#include<iostream>
using namespace std;

/*
int GetNumber(){
    return 42;
}*/
constexpr int GetNumber(){
    return 42;
}

constexpr int Add(int x, int y){
    return x+y;
}

constexpr int max(int x, int y){
    return x>y?x:y;
    // below multiple statements doesnt work in c++11
    /*if(x>y)
        return x;
    else
        return y;*/
}

int main(){

    constexpr int i = 10; // value of i is computed at compile time
                            //use i where it is expected to be compile time
    int arr[i];

    const int j = 10;  // Should be same thing ?
                        // As it is also compiled at compile time but if j would get value from 
                        // any func then it will become runtime 
    const int j = GetNumber(); // it will be at runtime
    //Now Behaves as constexpr function initialized at compile time now

    int arr1[j];

    //Now Behaves as constexpr function
    constexpr int i = GetNumber(); // gives error as GetNumber() doesnt gives constant at runtime
                                // so we will modify GetNumber to make constexpr
    // Now it initialized at compile time and same const j will also initialized at compile time


    //Now Behaves as normal function i.e. initialized at runtime
    int z = GetNumber();

    //Compile time
    constexpr int sum = Add(3, 5);

    constexpr int sum = Add(z, 5); // It works only with literals, and z is literal but not 
                                   // compile time constant so it shows error

    // Normal func i.e. runtime
    int sum2 = Add(3,5); 

    /*
    Constant expression rules:-
        1) Should accept & return literals types only   
            (void, scaler types(int, float, char), references etc..)
        2) should contain only single line statement that should be a return statement
            return x>y ? x:y   
            however in c++14, you can have if else in constexpr function
        3) All constexpr are implictly inline so they be define in header files
    */
}
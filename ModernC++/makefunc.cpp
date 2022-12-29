#include <iostream>
#include<memory>
using namespace std;

class Point{
    int a,b;
};

int main(){
    unique_ptr<int> p{new int(5)};
    {
        auto pt = make_unique<int> (10);
        auto pt2 = make_unique<Point> (1,2);
        auto ptArr = make_unique<int[]> (5);
        ptArr[0] = 11;
    }
    shared_ptr<int> sh{new int(5)};
    {
        auto pt = make_shared<int> (11);
        auto pt2 = make_shared<Point>(2,3);
        auto ptArr = make_shared<int[]>(5);
        ptArr[0] = 12;
    }
}
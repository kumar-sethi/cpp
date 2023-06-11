#include <iostream>
#include<vector>
using namespace std;

bool ascendingCompare(int a, int b) {
	return a < b;
}
bool descendingCompare(int a, int b) {
	return a > b;
}

// void sortAscending(vector<int>& numbersVector)
// {
// 	for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
// 	{
// 		int bestIndex = startIndex;

// 		for (int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++)
// 		{
// 			// We are doing comparison here
// 			if (ascendingCompare(numbersVector[currentIndex], numbersVector[bestIndex]))
// 				bestIndex = currentIndex;
// 		}

// 		swap(numbersVector[startIndex], numbersVector[bestIndex]);
// 	}
// }
// void sortDescending(vector<int>& numbersVector)
// {
// 	for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
// 	{
// 		int bestIndex = startIndex;

// 		for (int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++)
// 		{
// 			// We are doing comparison here
// 			if (descendingCompare(numbersVector[currentIndex], numbersVector[bestIndex]))
// 				bestIndex = currentIndex;
// 		}

// 		swap(numbersVector[startIndex], numbersVector[bestIndex]);
// 	}
// }


void customSort(vector<int>& numbersVector, bool(*compareFunctionPtr)(int, int))
{
	for (int startIndex = 0; startIndex < numbersVector.size(); startIndex++)
	{
		int bestIndex = startIndex;

		for (int currentIndex = startIndex + 1; currentIndex < numbersVector.size(); currentIndex++)
		{
			// We are doing comparison here
			if (compareFunctionPtr(numbersVector[currentIndex], numbersVector[bestIndex]))
				bestIndex = currentIndex;
		}

		swap(numbersVector[startIndex], numbersVector[bestIndex]);
	}
}


void printNumbers(vector<int>& numbersVector) {
	for (int i = 0; i < numbersVector.size(); ++i)
		cout << numbersVector[i] << ' ';
}

int main()
{
	vector<int> numbersVector{ 4,2,1,3,6,5 };
	//sortAscending(numbersVector);
	//sortDescending(numbersVector);
    // return type (*fnPtr) (int, int ) = &func
	//bool (*funcPtr)(int, int) = descendingCompare;
	bool (*funcPtr)(int, int) = ascendingCompare;
	customSort(numbersVector, funcPtr);
	printNumbers(numbersVector);
}


/*

#include<iostream>
using namespace std;

void Print(int count, char ch)
{
    for (int i=0; i<count; ++i)
        cout<<ch; 
    cout<<endl;
}
// Function Pointer/Functionpointer/fnptr/funcptr
int main()
{
    void(*fnPtr)(int, char) = Print;
    //fnPtr = Print;
    //fnPtr = &Print;
    Print(5,'%');
    fnPtr(8, '^');
// See: OneNote Function Pointer section it contains good understanding of the same.


}*/
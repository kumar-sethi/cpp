#include<iostream>
using namespace std;

template<class T>
class SharedPointer
{
    private:
        T* ptr = nullptr;
        int* ownerCount = new int(1);
public:
    SharedPointer(){};
    SharedPointer(T* ptr) : ptr(ptr), ownerCount(new int(1)){ }

    SharedPointer(const SharedPointer& obj)
    {
        this->ptr = obj.ptr; // share the underlying pointer
        this->ownerCount = obj.ownerCount; // share ownerCount
        if (nullptr != obj.ptr)
        {
            // if the pointer is not null, increment the ownerCount
            (*this->ownerCount)++; 
        }
    }
    // copy assignment
    SharedPointer& operator=(const SharedPointer & obj)
    {
        // cleanup any existing data
        // Assign incoming object's data to this object
        this->ptr = obj.ptr; // share the underlying pointer
        this->ownerCount = obj.ownerCount; // share ownerCount
        if (nullptr != obj.ptr)
        {
            // if the pointer is not null, increment the ownerCount
            (*this->ownerCount)++; 
        }
    }

    int getCount() const
    {
        if(this->ownerCount)
        return *(this->ownerCount);// return *ownerCount;
    }

    SharedPointer* operator ->(){
        return ptr;
    }
    SharedPointer& operator *(){
        return *ptr;
    }
    ~SharedPointer(){
        if(ownerCount && *ownerCount!=0)
        (*ownerCount)--;
        if(*ownerCount==0){
            if(ptr != nullptr)
                delete ptr;
            delete ownerCount;
        }
    }




};


/*
	T* get() const
	{
		return this->ptr;
	}

	T* operator->() const
	{
		return this->ptr;
	}

	T& operator*() const
	{
		return this->ptr;
	}

	~SharedPointer() // destructor
	{
		__cleanup__();
	}

private:
	void __cleanup__()
	{
		(*refCount)--;
		if (*refCount == 0)
		{
			if (nullptr != ptr)
				delete ptr;
			delete refCount;
		}
	}

*/

int main()
{
    SharedPointer<int> obj;
    cout << obj.getCount() << endl; // prints 0
    SharedPointer<int> box1(new int(54));
    cout << box1.getCount() << endl; // prints 1
    SharedPointer<int> box2(box1); // calls copy constructor
    cout << box1.getCount() << endl; // prints 2
    cout << box2.getCount() << endl; // also prints 2
    cout<<*box2;
 
    return 0;
}
#include<iostream>
using namespace std;

template<class T>

class Node{
    T value;
    public:
        Node<T> *next{nullptr}; //Aggregate Initialization:- Next ptr to point next Node
        Node(){};
        Node(const T &data){
            value = data;  
        }
        T& getdata(){return value;}
        void setdata(const T& data){ value = data;};
        ~Node(){  next = nullptr;    };
};
template<class T>
class MyLL{
    Node<T> *head{nullptr};   
    Node<T> *tail{nullptr};   
    int length = 0;
    public:
    void push(const T& data){
        Node<T>* newNode = new Node<T>(data);
        if(length == 0)
        {
            head = newNode;
            tail = newNode;
            newNode = nullptr;
        }else{
            newNode->next = head ;
            head = newNode;  
        }
        length++;
    }
    void pop(){
        if(head == nullptr && tail == nullptr)
            return;
        else
        {
            Node<T>* trav = head;
            while(trav->next != tail){
                trav = trav->next; 
            }
            //trav will have one prev posn of tail
            trav->next = nullptr; 
            delete tail;
            tail = trav;
            length--;
        }
    }

    void printList(){
        Node<T> *trav = head;
        while(trav!=nullptr){
            cout<<trav->getdata()<< "  ";
            trav = trav->next;
        }
    }

void append(const T& data){

    Node<T>* newnode = new Node<T> (data);
    if(length == 0)
    {
        head = newnode;
        tail = newnode;
    }
    else{   
        tail->next = newnode;
        tail = newnode;
        }
    length++;
}
T& getAtIndex(int index){
  Node<T>* trav = head;
  if(index==0)
    return head->getdata();

  while(index){
      trav = trav ->next;
      index--;
  }  
  return trav->getdata();

}
};

main(){

    MyLL<int> *myll = new MyLL<int>();
    myll->push(15);
    myll->push(5);
    myll->push(11);
    myll->append(100);
    myll->push(51);
    myll->push(92);

    myll->printList();
    cout<<endl<<myll->getAtIndex(5);
}


//Reference:- https://medium.com/@terselich/create-you-own-linked-list-in-c-8deb653273
#include<iostream>
#include<stack>
using namespace std;

//template<class T>
class Node{
    int value;
    public:
        Node *next{nullptr}; //Aggregate Initialization:- Next ptr to point next Node
        Node(){};
        Node(const int &data){
            value = data;  
        }
        int& getdata(){return value;}
        void setdata(const int& data){ value = data;};
        ~Node(){  next = nullptr;    };
};


bool isPalin(Node* head){

    stack<int> s;

    while(head!= NULL){
        s.push(head->getdata());
        head = head->next;
    }

    while(head!=NULL){
        if(s.top() == head->getdata())
            return false;

        s.pop();
        head= head->next;
    }

}


bool isPalin(Node<char>* head){
    Node<char>* slow = head, *fast = head, *midnode = head, *prev_of_slow = head;

    if(head != NULL && head->next != NULL){
        while(fast!=nullptr && fast->next!= nullptr){
            fast = fast->next->next;
            prev_of_slow = slow;
            slow = slow->next;
        } // inc fast by 2 and slow by 1

        if(fast!=NULL){
            midnode = slow;
            slow = slow->next;
        }
        
    }

}


#include<iostream>
#include"node.h"
using namespace std;


Node* reverseLL(Node* head){
    Node* curr = head;
    Node* prev = nullptr;

    while(curr!=nullptr){
        Node* node;
        node = curr->next;
        curr->next = prev;
        prev = curr;
        curr = node;
    }
    return prev;
}

main(){
    Node* h1 = new Node(12);
    Node::makeLL(&h1);
    Node::printLL(h1);
    cout<<endl;
    h1 = reverseLL(h1);
    h1->printLL(h1);
}



#include<iostream>
struct Node{

    Node* next = nullptr;
    int data;
    Node(){}
    Node(int v, Node* next = nullptr):data(v){}

    static void printLL(Node*);
    static void makeLL(Node**);
};

void Node::printLL(Node* head){
    while(head!=nullptr){
        std::cout<<head->data<<"\t";
        head = head->next;
    }
}
void Node::makeLL(Node** h){
    int x = 5;
    while(x>0){
        int val = (*h)->data + 1;
        Node* node = new Node(val);
        node->next = *h;
        *h = node;
        x--;
    }
}



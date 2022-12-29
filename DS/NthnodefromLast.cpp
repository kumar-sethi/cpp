#include<iostream>
#include"node.h"
using namespace std;

void nthfromend(Node* head, int n){

    Node* ref = head;
    int len = 0;
    while(ref!=nullptr){
        len++;
        ref = ref->next;
    }
    int i = 0;//= len-n+1
    while(i<(len-n)){
        head = head->next;
        i++;
    }
    if(head)
        cout<<head->data;
}


main(){
    Node* h1 = new Node(1);
    Node::makeLL(&h1);
    Node::printLL(h1);

    nthfromend(h1, 0);

}
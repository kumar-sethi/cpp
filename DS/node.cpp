/* #include"node.h"
void Node::printLL(Node* head){
    while(head!=nullptr){
        cout<<head->data<<"\t";
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
main(){}
 */
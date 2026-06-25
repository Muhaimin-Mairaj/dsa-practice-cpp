#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int val);
};

void traverse(Node* &head);
void insert_at_begg(Node* &head, int val);
void del_list(Node* &head);


// SOLUTION TO THE PROBLEM
Node* intersection(Node* head1, Node* head2){
    Node* head3 = nullptr;
    Node* curr = nullptr;

    while(head1 && head2){
        if((head1->data == head2->data)){
            if(curr == nullptr){
                curr = new Node(head1->data);
                head3 = curr;
            }
            else if(curr->data != head1->data){
                curr->next = new Node(head1->data);
                curr = curr->next;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        else if(head1->data < head2->data) head1 = head1->next;
        else head2 = head2->next;
    }
    return head3;
}
// SOLUTION ENDS


int main(){
    Node* head = nullptr;
    insert_at_begg(head,6);
    insert_at_begg(head,4);
    insert_at_begg(head,3);
    insert_at_begg(head,2);
    insert_at_begg(head,2);
    insert_at_begg(head,1);
    traverse(head);

    Node* head2 = nullptr;
    insert_at_begg(head2,4);
    insert_at_begg(head2,3);
    insert_at_begg(head2,2);
    insert_at_begg(head2,2);
    insert_at_begg(head2,1);
    traverse(head2);

    Node* head3 = intersection(head, head2);
    traverse(head3);

    del_list(head);
    del_list(head2);
    del_list(head3);
    return 0;
}





Node::Node(int val){
    data = val;
    next = nullptr;
}

void traverse(Node* &head){
    Node* curr = head;
    while(curr){
        std::cout<< curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL\n";
}

void insert_at_begg(Node* &head, int val){
    Node* node = new Node(val);

    node->next = head;
    head = node;
    return;
}

void del_list(Node* &head){
    while(head){
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}
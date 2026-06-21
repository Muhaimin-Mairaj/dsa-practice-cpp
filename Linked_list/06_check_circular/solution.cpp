#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int val);
};

void traverse_list(Node* &head);
void insert_at_begg(Node* &head, int val);
void make_circular(Node* &head);
void del_list(Node* &head);


// SOLUTION TO THE PROBLEM
void check_circular(Node* &head){
    if(head == nullptr){
        std::cout << "True\n";
        return;
    }

    Node* curr = head;
    while(curr != nullptr && curr->next != head) curr = curr->next;

    if(curr == nullptr) std::cout << "False\n";
    else std::cout << "True\n";
}
// SOLUTION ENDS

 
int main(){
    Node* head = nullptr;
    insert_at_begg(head,60);
    insert_at_begg(head,50);
    insert_at_begg(head,40);
    insert_at_begg(head,30);
    insert_at_begg(head,20);
    insert_at_begg(head,10);
    traverse_list(head);

    check_circular(head);

    make_circular(head);
    check_circular(head);

    del_list(head);
    return 0;
}






Node::Node(int val){
    data = val;
    next = nullptr;
}

void insert_at_begg(Node* &head, int val){
    Node* node = new Node(val);

    node->next = head;
    head = node;
    return;
}

void make_circular(Node* &head){
    Node* curr = head;
    while(curr->next != nullptr) curr = curr->next;
    curr->next = head;
}


void traverse_list(Node* &head){
    Node* curr = head;
    while(curr){
        std::cout<< curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL\n";
}

void del_list(Node* &head){
    Node* last = head;
    while(last->next != head) last = last->next;
    last->next = nullptr;

    while(head){
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}
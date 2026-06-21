#include <iostream>

class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int val);
};

void traverse(Node* &head);
void insert_at_begg(Node* &head, int val);
void del_list(Node* &head);


// SOLUTION TO THE PROBLEM
void reverse(Node* &head){
    Node* curr = head;
    while(curr->next != nullptr){
        Node* next = curr->next;
        
        curr->next = curr->prev;
        curr->prev = next;
        curr = next;
    }
    curr->next = curr->prev;
    curr->prev = nullptr;
    head = curr;
}
// SOLUTION ENDS

int main(){
    Node* head = nullptr;
    insert_at_begg(head,3);
    insert_at_begg(head,2);
    insert_at_begg(head,1);
    traverse(head);

    reverse(head);
    traverse(head);
    return 0;
}






Node::Node(int val){
    data = val;
    prev = next = nullptr;
}


void traverse(Node* &head){
    if(head == nullptr){
        std::cout << "NULL\n";
        return;
    }

    Node* curr = head;
    while(curr != nullptr){
        std::cout << curr->data << " <-> ";
        curr = curr->next;
    }
    std::cout << "NULL\n";
}


void insert_at_begg(Node* &head, int val){
    Node* node = new Node(val);

    if(head == nullptr){
        head = node;
        return;
    }

    node->next = head;
    head->prev = node;
    head = node;
}

void del_list(Node* &head){
    while(head){
        Node* temp = head->next;
        delete head;
        temp->prev = nullptr;
        head = temp;
    }
}
#include <iostream>

struct Node{
    int data;
    Node* prev, *next;
    Node(int val);
};

void traverse(Node* &head);
void insert_at_begg(Node* &head, int val);
void del_list(Node* &head);


// SOLUTION TO THE PROBLEM
void insert_sorted(Node* &head, int val){
    if(head == nullptr || (head->data >= val)){
        insert_at_begg(head,val);
        return;
    }

    Node* curr = head;
    while((curr->next != nullptr) && (curr->next->data < val)) curr = curr->next;

    Node* node = new Node(val);
    if(curr->next == nullptr){
        curr->next = node;
        node->prev = curr;
        return;
    }

    node->next = curr->next;
    curr->next = node;
    node->next->prev = node;
    node->prev = curr;
}
// SOLUTION ENDS

int main(){
    Node* head = nullptr;
    insert_at_begg(head,12);
    insert_at_begg(head,10);
    insert_at_begg(head,8);
    insert_at_begg(head,5);
    insert_at_begg(head,3);
    traverse(head);

    insert_sorted(head,9);
    traverse(head);

    del_list(head);
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
        head = temp;
    }
}
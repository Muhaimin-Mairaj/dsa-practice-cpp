#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int val);
};

void traverse_list(Node* &head);
void insert_at_begg(Node* &head, int val);
void del_list(Node* &head);


// SOLUTION TO THE PROBLEM
void middle_node(Node* &head){
    if(head == nullptr) return;

    Node* slow = head;
    Node* fast = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    std::cout << "Middle Node: " << slow->data << "\n";
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

    middle_node(head);

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


void traverse_list(Node* &head){
    Node* curr = head;
    while(curr){
        std::cout<< curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL\n";
}

void del_list(Node* &head){
    while(head){
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}
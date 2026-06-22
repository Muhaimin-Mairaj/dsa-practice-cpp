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
void swap_pairwise(Node* &head){
    if(head == nullptr || head->next == nullptr) return;

    Node* curr = head;
    head = head->next;
    Node* prev = nullptr;
    while(curr != nullptr && curr->next != nullptr){
        Node* temp = curr->next;
        curr->next = curr->next->next;
        temp->next = curr;
        
        prev = curr;
        curr = curr->next;
        if(curr != nullptr && curr->next != nullptr) prev->next = curr->next;
    }

}
// SOLUTION ENDS

 
int main(){
    Node* head = nullptr;
    insert_at_begg(head,1);
    insert_at_begg(head,2);
    insert_at_begg(head,5);
    insert_at_begg(head,7);
    insert_at_begg(head,8);
    traverse_list(head);

    swap_pairwise(head);
    traverse_list(head); 

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
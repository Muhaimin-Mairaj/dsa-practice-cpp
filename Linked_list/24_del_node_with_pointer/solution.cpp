#include <iostream>

struct Node{
    int data;
    Node* next;
    Node(int val);
};

void traverse(Node* &head);
void insert_at_begg(Node* &head, int val);
void del_list(Node* &head);


// SOLUTION TO THE PROBLEM
// This method has edge case which is pointer to last node, in that case, we will need head pointer to traverse the list.
// Otherwise the time and space complexity of this solution is O(1).
void del_node_with_pointer(Node* pointer){
    if(pointer == nullptr || pointer->next == nullptr) return;

    pointer->data = pointer->next->data;
    Node* temp = pointer->next;
    pointer->next = temp->next;
    delete temp;
}
// SOLUTION ENDS


int main(){
    Node* head = nullptr;
    insert_at_begg(head,30);
    insert_at_begg(head,4);
    insert_at_begg(head,20);
    insert_at_begg(head,10);
    traverse(head);

    del_node_with_pointer(head->next->next);
    traverse(head);

    del_list(head);
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
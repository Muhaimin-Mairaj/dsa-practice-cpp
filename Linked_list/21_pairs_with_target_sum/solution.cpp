#include <iostream>

struct Node{
    int data;
    Node* prev, *next;
    Node(int val);
};

void traverse(Node* &head);
void insert_at_end(Node* &head, int val);
void del_list(Node* &head);


// SOLUTION TO THE PROBLEM
// (The following problem uses O(1) space and has O(n) time complexity). 
// (This problem can also be solved using hash set with O(n) time and space complexity).
void pairs_with_target_sum(Node* head, int target){
    Node* tail = head;
    while(tail->next != nullptr) tail = tail->next;

    while(head->data <= tail->data){
        if((head->data + tail->data) == target){
            std::cout << "(" << head->data << ", " << tail->data << ") ";
            head = head->next;
            tail = tail->prev;
        }
        else if((head->data + tail->data) < target) head = head->next;
        else tail = tail->prev;
    }
}
// SOLUTION ENDS

int main(){
    Node* head = nullptr;
    insert_at_end(head,1);
    insert_at_end(head,2);
    insert_at_end(head,4);
    insert_at_end(head,5);
    insert_at_end(head,6);
    insert_at_end(head,8);
    insert_at_end(head,9);
    traverse(head);

    pairs_with_target_sum(head,7);
    
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

void insert_at_end(Node* &head, int val){
    Node* node = new Node(val);

    if(head == nullptr){
        head = node;
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = node;
    node->prev = curr;
}

void del_list(Node* &head){
    while(head){
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}
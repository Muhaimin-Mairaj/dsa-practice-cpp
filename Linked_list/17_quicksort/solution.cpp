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
Node* getTail(Node* head){
    while(head->next) head = head->next;
    return head;
}

Node* partition(Node* head, Node* tail){
    Node *pivot = head, *pre = head, *curr = head;

    while(curr != tail->next){
        if(curr->data < pivot->data){
            std::swap(curr->data, pre->next->data);
            pre = pre->next;
        }
        curr = curr->next;
    }
    std::swap(pre->data, pivot->data);
    return pre;
}

void quickSortHelper(Node* head, Node* tail){
    if(head != nullptr && head != tail){
        Node* pivot = partition(head,tail);
        quickSortHelper(head,pivot);
        quickSortHelper(pivot->next, tail);
    }
}

Node* quickSort(Node* head){
    Node* tail = getTail(head);

    quickSortHelper(head,tail);
    return head;
}
// SOLUTION ENDS


int main(){
    Node* head = nullptr;
    insert_at_begg(head,5);
    insert_at_begg(head,4);
    insert_at_begg(head,9);
    insert_at_begg(head,12);
    insert_at_begg(head,15);
    traverse(head);

    head = quickSort(head);
    traverse(head);

    del_list(head);
    traverse(head);
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
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
Node* partition_list(Node* head, int val){

    Node* curr = new Node(val);
    Node* before = nullptr;
    Node* after = nullptr;
    Node* newHead = curr;
    int count = 1;

    while(head){
        Node* node = new Node(head->data);
        if(head->data < val){
            node->next = curr;
            if(before) before->next = node;
            before = node; 
            if(newHead == curr) newHead = before;
        }
        else if (head->data == val){
            if(count != 1){
                node->next = curr->next;
                curr->next = node;
                curr = curr->next;
            }
            count++;
        }
        else if(head->data > val){
            if(!after) curr->next = node;
            else after->next = node;
            after = node;
        }
        Node* temp = head->next;
        delete head;
        head = temp;
    }

    return newHead;
}
// SOLUTION ENDS


int main(){
    Node* head = nullptr;
    insert_at_begg(head,3);
    insert_at_begg(head,2);
    insert_at_begg(head,5);
    insert_at_begg(head,2);
    insert_at_begg(head,3);
    insert_at_begg(head,4);
    insert_at_begg(head,1);
    traverse(head);

    Node* newHead = partition_list(head,3);
    traverse(newHead);

    del_list(newHead);
    traverse(newHead);
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
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
int get_length(Node* head){
    int len = 0;
    while(head){
        len++;
        head = head->next;
    }
    return len;
}

Node* rotate_list_by_k(Node* &head, int k){
    k = k % get_length(head); 
    if(k == 0) return head;

    Node* curr = head;
    Node* temp = nullptr;
    int count = 1;
    while(curr->next){
        if(count == k){
            temp = curr->next;
            curr->next = nullptr;
            curr = temp;
        }
        else curr = curr->next;
        count++;
    }
    curr->next = head;
    return temp;
}
// SOLUTION ENDS


int main(){
    Node* head = nullptr;
    insert_at_begg(head,6);
    insert_at_begg(head,5);
    insert_at_begg(head,4);
    insert_at_begg(head,3);
    insert_at_begg(head,2);
    insert_at_begg(head,1);
    traverse(head);

    head = rotate_list_by_k(head,4);
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
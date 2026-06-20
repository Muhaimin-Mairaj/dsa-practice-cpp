#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int val);
};

void traverse_list(Node* &head);

void insert_at_begg(Node* &head, int val);

Node* del_at_pos(Node* &head, int pos){
    if(pos < 1) return nullptr;

    if(pos == 1){
        if(head != nullptr){
            delete head;
            head = nullptr;
        }
        return nullptr;
    }

    Node* curr = head;
    for(int i = 1; i < pos-1 && curr != nullptr; i++){
        curr = curr->next;
    }

    if(curr == nullptr) return nullptr;

    Node* temp = curr->next->next;
    delete curr->next;
    curr->next = temp;
    return head;
}

void del_every_kth(Node* &head, int k){
    int i = 0;
    while(del_at_pos(head,k + k*i - i)) i += 1;
}

int main(){
    Node* head = nullptr;
    insert_at_begg(head,6);
    insert_at_begg(head,5);
    insert_at_begg(head,4);
    insert_at_begg(head,3);
    insert_at_begg(head,2);
    insert_at_begg(head,1);
    traverse_list(head);

    del_every_kth(head,2);
    traverse_list(head);
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
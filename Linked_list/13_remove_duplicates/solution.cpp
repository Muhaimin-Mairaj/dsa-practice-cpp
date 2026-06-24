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
void remove_duplicates(Node* &head){
    Node* curr = head->next;
    Node* prev = head;

    while(curr){
        if(prev->data == curr->data){
            Node* temp = curr->next;
            prev->next = curr->next;
            delete curr;
            curr = temp;
        }
        else{
            prev = curr;
            curr = curr->next;
        }
    }

}
// SOLUTION ENDS


int main(){
    Node* head = nullptr;;
    insert_at_begg(head,60);
    insert_at_begg(head,43);
    insert_at_begg(head,43);
    insert_at_begg(head,21);
    insert_at_begg(head,11);
    insert_at_begg(head,11);
    insert_at_begg(head,11);
    traverse(head);

    remove_duplicates(head);
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
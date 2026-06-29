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
Node* merge_lists(Node* head1, Node* head2){
    Node* newHead = new Node(0);
    Node* curr = newHead;

    while(head1 && head2){
        if(head1->data < head2->data){
            curr->next = head1;
            head1 = head1->next;
        }
        else{
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }
    if(!head1) curr->next = head2;
    else curr->next = head1;

    Node* temp = newHead->next;
    delete newHead;
    return temp;
} 
// SOLUTION ENDS


int main(){
    Node* head1 = nullptr;
    insert_at_begg(head1,40);
    insert_at_begg(head1,15);
    insert_at_begg(head1,10);
    insert_at_begg(head1,5);
    traverse(head1);

    Node* head2 = nullptr;
    insert_at_begg(head2,20);
    insert_at_begg(head2,3);
    insert_at_begg(head2,2);
    traverse(head2);

    Node* newHead = merge_lists(head1, head2);
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
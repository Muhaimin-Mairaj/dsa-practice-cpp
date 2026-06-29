#include <iostream>

struct Node{
    int data;
    Node* next;
    Node(int val);
};

void traverse(Node* &last);
void insert_at_begg(Node* &last, int val);
void del_list(Node* &last);


// SOLUTION TO THE PROBLEM
Node* split_list(Node* &last){
    if(last == nullptr || last->next == last) return last;

    Node* slow = last->next;
    Node* fast = slow->next;

    while(fast != last && fast != last->next){
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* temp = slow->next;
    slow->next = last->next;
    last->next = temp;
    return slow;
}
// SOLUTION ENDS

int main(){
    Node* last = nullptr;
    insert_at_begg(last,5);
    insert_at_begg(last,4);
    insert_at_begg(last,3);
    insert_at_begg(last,2);
    insert_at_begg(last,1);
    traverse(last);

    Node* firstListlast = split_list(last);
    traverse(firstListlast);
    traverse(last);

    del_list(firstListlast);
    del_list(last);
    return 0;
}






Node::Node(int val){
    data = val;
    next = nullptr;
}


void traverse(Node* &last){
    if(last == nullptr){
        std::cout << "NULL\n";
        return;
    }

    Node* curr = last->next;
    while(true){
        std::cout << curr->data;
        if(curr == last) break;
        curr = curr->next;
        std::cout << " -> ";
    }
    std::cout << "\n";
}


void insert_at_begg(Node* &last, int val){
    if(last == nullptr){
        Node* node = new Node(val);
        last = node;
        last->next = last;
        return;
    }

    Node* node = new Node(val);
    node->next = last->next;
    last->next = node;
}

void del_list(Node* &last){
    if(last == nullptr) return;

    Node* head = last->next;
    last->next = nullptr;
    while(head){
        Node* temp = head->next;
        delete head;
        head = temp;
    }
    last = nullptr;
}

#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int val);
};

void traverse_list(Node* &head);
void del_list(Node* &head);


// SOLUTION TO THE PROBLEM
void detect_cycle(Node* &head){
    if(head == nullptr){
        std::cout << "False\n";
        return;
    }
    
    Node* slow = head;
    Node* fast = head->next;
    while(fast != nullptr && fast->next != nullptr){
        if(slow == fast){
            std::cout << "True\n";
            return;
        }
        slow = slow->next;
        if(fast->next) fast = fast->next->next;
    }

    std::cout << "False\n";
}
// SOLUTION ENDS

 
int main(){
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = head->next;
    detect_cycle(head);
    head->next->next->next = nullptr;
    del_list(head);


    Node* head2 = new Node(1);
    head2->next = new Node(8);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    detect_cycle(head2);
    del_list(head2);

    return 0;
}






Node::Node(int val){
    data = val;
    next = nullptr;
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
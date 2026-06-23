#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int val);
};

void traverse(Node* &head);
void del_list(Node* &head);


// SOLUTION TO THE PROBLEM (This solution is almost similar to finding first node of a loop with minor changes)
void remove_loop(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;
            while(slow->next != fast->next){
            slow = slow->next;
            fast = fast->next;
            }
            fast->next = nullptr;
            return;
        }

    }
    
}
// SOLUTION ENDS

 
int main(){
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = head->next;
    remove_loop(head);
    traverse(head);
    del_list(head);


    Node* head2 = new Node(1);
    head2->next = new Node(8);
    head2->next->next = new Node(3);
    head2->next->next->next = new Node(4);
    remove_loop(head2);
    traverse(head2);
    del_list(head2);

    return 0;
}






Node::Node(int val){
    data = val;
    next = nullptr;
}
 

void del_list(Node* &head){
    while(head){
        Node* temp = head->next;
        delete head;
        head = temp;
    }
}


void traverse(Node* &head){
    Node* curr = head;
    while(curr){
        std::cout<< curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL\n";
}
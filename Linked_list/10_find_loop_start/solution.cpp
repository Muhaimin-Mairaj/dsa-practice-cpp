#include <iostream>

class Node{
public:
    int data;
    Node* next;
    Node(int val);
};

void del_list(Node* &head);


// SOLUTION TO THE PROBLEM
void find_loop_start(Node* &head){
    Node* slow = head;
    Node* fast = head;

    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            slow = head;
            while(slow != fast){
            slow = slow->next;
            fast = fast->next;
            }
            std::cout << slow->data << "\n";
            return;
        }

    }
    std::cout << "-1\n";
}
// SOLUTION ENDS

 
int main(){
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next;
    find_loop_start(head);
    head->next->next->next->next->next = nullptr;
    del_list(head);


    Node* head2 = new Node(1);
    head2->next = new Node(3);
    head2->next->next = new Node(2);
    head2->next->next->next = new Node(1);
    find_loop_start(head2);
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
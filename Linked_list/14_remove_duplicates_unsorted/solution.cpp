#include <iostream>
#include <unordered_set>

class Node{
public:
    int data;
    Node* next;
    Node(int val);
};

void traverse(Node* &head);
void insert_at_begg(Node* &head, int val);
void del_list(Node* &head);


// SOLUTION TO THE PROBLEM (this solution can be done in O(1) space complexity, but then time complexity would go from O(n) to O(n^2))
void remove_duplicates_unsorted(Node* &head){
    Node* curr = head;
    Node* prev = nullptr;
    std::unordered_set<int> s;

    while(curr){
        if(s.find(curr->data) != s.end()){
            prev->next = curr->next;
            delete curr;
            curr = prev->next;
        }
        else{
            s.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }    
}
// SOLUTION ENDS


int main(){
    Node* head = nullptr;
    insert_at_begg(head,21);
    insert_at_begg(head,43);
    insert_at_begg(head,41);
    insert_at_begg(head,21);
    insert_at_begg(head,12);
    insert_at_begg(head,11);
    insert_at_begg(head,12);
    traverse(head);

    remove_duplicates_unsorted(head);
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
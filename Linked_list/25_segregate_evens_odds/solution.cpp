#include <iostream>
#include <vector>

struct Node{
    int data;
    Node* next;
    Node(int val);
};

void traverse(Node* &head);
void insert_at_begg(Node* &head, int val);
void del_list(Node* &head);


// SOLUTION TO THE PROBLEM (This solution runs in O(n) time and space complexity)
void segregate_nodes(Node* head){
    if(head == nullptr || head->next == nullptr) return;

    std::vector<int> v;
    Node* curr = head;
    int evens = 0;
    while(curr){
        v.push_back(curr->data);
        if(curr->data % 2 == 0) evens++;
        curr = curr->next;
    }

    Node* temp = head;
    for(int i = 1; i <= evens; i++) temp = temp->next;

    for(int i = 0; i < v.size(); i++){
        if(v[i] % 2 == 0){
            head->data = v[i];
            head = head->next;
        }
        else{
            temp->data = v[i];
            temp = temp->next;
        }
    }
}
// SOLUTION ENDS


int main(){
    Node* head = nullptr;
    insert_at_begg(head,6);
    insert_at_begg(head,4);
    insert_at_begg(head,2);
    insert_at_begg(head,9);
    insert_at_begg(head,8);
    insert_at_begg(head,15);
    insert_at_begg(head,17);
    traverse(head);

    segregate_nodes(head);
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
#include <iostream>
#include <unordered_set>

struct Node{
    int data;
    Node* next;
    Node(int val);
};

void traverse(Node* &head);
void insert_at_begg(Node* &head, int val);
void del_list(Node* &head);


// SOLUTION TO THE PROBLEM
void insert_helper(Node* &head, Node* &curr, std::unordered_set<int> &st){
    while(head){
        if(st.find(head->data) == st.end()){
            curr->next = new Node(head->data);
            curr = curr->next;
            st.insert(head->data);
        }
        head = head->next;
    }
}

Node* union_of_lists(Node* head1, Node* head2){
    Node* newHead = new Node(-1);
    Node* curr = newHead;
    std::unordered_set<int> st;

    insert_helper(head1,curr,st);
    insert_helper(head2,curr,st);    


    Node* temp = newHead->next;
    delete newHead;
    return temp;
}
// SOLUTION ENDS


int main(){
    Node* head1 = nullptr;
    insert_at_begg(head1,5);
    insert_at_begg(head1,2);
    insert_at_begg(head1,2);
    insert_at_begg(head1,1);
    insert_at_begg(head1,5);
    insert_at_begg(head1,1);
    traverse(head1);

    Node* head2 = nullptr;
    insert_at_begg(head2,1);
    insert_at_begg(head2,7);
    insert_at_begg(head2,6);
    insert_at_begg(head2,5);
    insert_at_begg(head2,4);
    traverse(head2);

    Node* newHead = union_of_lists(head1, head2);
    traverse(newHead);


    del_list(head1);
    del_list(head2);
    del_list(newHead);
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
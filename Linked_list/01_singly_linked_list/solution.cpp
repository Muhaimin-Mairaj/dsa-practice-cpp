#include <iostream>

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

// Traversal (Iterative)
void traverse_itr(Node* head){
    Node* curr = head;
    while(curr){
        std::cout<< curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL\n";
}

// Traversal (Recursive)
void traverse_rec(Node* head){
    if(head == nullptr){
        std::cout << "NULL\n";
        return;
    }

    std::cout << head->data << " -> ";
    traverse_rec(head->next);
}



// Insertion at the beginning
void insert_at_begg(Node* &head, int val){
    Node* node = new Node(val);

    node->next = head;
    head = node;
    return;
}

// Insertion at the end
void insert_at_end(Node* &head, int val){
    Node* node = new Node(val);

    if(head == nullptr){
        head = node;
        return;
    }

    Node* curr = head;
    while(curr->next){
        curr = curr->next;
    }

    curr->next = node;
    return;
}

// Insertion at specific position
void insert_at_pos(Node* &head, int pos, int val){
    if(pos < 1) return;

    if(pos == 1){
        insert_at_begg(head,val);
        return;
    }

    Node* curr = head;
    for(int i = 1; i < pos-1 && curr != nullptr; i++){
        curr = curr->next;
    }

    if(curr == nullptr){
        return;
    }

    Node* node = new Node(val);
    node->next = curr->next;
    curr->next = node;
    return;
}


// Delete from beginning
void del_from_begg(Node* &head){
    if(head == nullptr) return;

    Node* curr = head;
    head = head->next;
    delete curr;
}

// Delete from end
void del_from_end(Node* &head){
    if(head == nullptr) return;

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* curr = head;
    while(curr->next->next != nullptr){
        curr = curr->next;
    }
    Node* temp = curr->next;
    delete temp;
    curr->next = nullptr;

}

// Delete at a specific position
void del_at_pos(Node* &head, int pos){
    if(pos < 1) return;

    if(pos == 1){
        del_from_begg(head);
        return;
    }

    Node* curr = head;
    for(int i = 1; i < pos-1 && curr != nullptr; i++){
        curr = curr->next;
    }

    if(curr == nullptr) return;

    Node* temp = curr->next->next;
    delete curr->next;
    curr->next = temp;
}

// Delete complete linked list
void del_list(Node* &head){
    if(head == nullptr) return;

    while(head) del_from_begg(head);
}


// Searching for value in linked list
void search_val(Node* &head, int key){
    if(head == nullptr) return;

    Node* curr = head;
    while(curr != nullptr){
        if(curr->data == key){
            std::cout << key <<
             " exists in linked list\n";
            return;
        }
        curr = curr->next;
    }

    std::cout << key << " does not exist in linked list\n";
}



// Reverse linked list
void reverse(Node* &head){
    if(head == nullptr || head->next == nullptr) return;

    Node* prev = nullptr;
    Node* curr = head;

    while(curr != nullptr){
        Node* next = curr->next;

        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

int main(){
    Node* head = nullptr;;
    insert_at_begg(head,3);
    insert_at_begg(head,2);
    insert_at_begg(head,1);
    insert_at_end(head,4);
    insert_at_end(head,5);
    insert_at_pos(head,4,40);
    insert_at_pos(head,6,10);

    traverse_itr(head);

    del_from_begg(head);
    del_from_end(head);
    del_at_pos(head,3);

    traverse_itr(head);

    search_val(head,4);
    search_val(head,5000);
    
    reverse(head);
    traverse_rec(head);

    del_list(head);

    return 0;
}
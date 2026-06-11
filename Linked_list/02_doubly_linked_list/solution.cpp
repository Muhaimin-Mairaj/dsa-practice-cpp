#include <iostream>

class Node{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = next = nullptr;
    }
};

// Traverse forward iteratively
void traverse_fwd_itr(Node* &head){
    if(head == nullptr){
        std::cout << "NULL\n";
        return;
    }

    Node* curr = head;
    while(curr != nullptr){
        std::cout << curr->data << " <-> ";
        curr = curr->next;
    }
    std::cout << "NULL\n";
}

// Traverse forward recursively
void traverse_fwd_rec(Node* head){
    if(head == nullptr){
        std::cout << "NULL\n";
        return;
    }

    std::cout << head->data << " <-> ";
    traverse_fwd_rec(head->next);
}

// Traverse backward iteratively
void traverse_bwd_itr(Node* &head){
    if(head == nullptr){
        std::cout << "NULL\n";
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr) curr = curr->next;

    while(curr != nullptr){
        std::cout << curr->data << " <-> ";
        curr = curr->prev;
    }
    std::cout << "NULL\n";
}

// Traverse backward recursively
void traverse_bwd_rec(Node* head){
    if(head == nullptr){
        return;
    }

    traverse_bwd_rec(head->next);
    std::cout << head->data << " <-> ";
    if(head->prev == nullptr) std::cout << "NULL\n";
}

// Insert at beginning of doubly linked list
void insert_at_begg(Node* &head, int val){
    Node* node = new Node(val);

    if(head == nullptr){
        head = node;
        return;
    }

    node->next = head;
    head->prev = node;
    head = node;
}

// Insert at end of doubly linked list
void insert_at_end(Node* &head, int val){
    Node* node = new Node(val);

    if(head == nullptr){
        head = node;
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = node;
    node->prev = curr;
}

// Insert at specific position 
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

    if(curr == nullptr) return;

    if(curr->next == nullptr){
        insert_at_end(head,val);
        return;
    }

    Node* node = new Node(val);
    node->next = curr->next;
    node->next->prev = node;
    curr->next = node;
    node->prev = curr;
}



// Deletion from beginning
void  del_from_begg(Node* &head){
    if(head == nullptr) return;

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head->next;
    delete head;
    head = temp;
    head->prev = nullptr;
}

// Deletion from end
void del_from_end(Node* &head){
    if(head == nullptr) return;

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        return;
    }

    Node* curr = head;
    while(curr->next != nullptr) curr = curr->next;

    curr->prev->next = nullptr;
    delete curr;
}

// Deleteion at a specific position
void del_at_pos(Node* &head, int pos){
    if(pos < 1) return;

    if(pos == 1){
        del_from_begg(head);
        return;
    }

    Node* curr = head;
    for(int i = 1; i < pos && curr != nullptr; i++){
        curr = curr->next;
    }

    if(curr == nullptr) return;

    if(curr->next == nullptr){
        del_from_end(head);
        return;
    }

    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
}

// Deleteion of complete doubly linked list
void del_list(Node* &head){
    if(head == nullptr) return;

    while(head) del_from_begg(head);
}


// Searching for a specific value
void search_val(Node* &head, int key){
    if(head == nullptr) return;

    Node* curr = head;
    while(curr != nullptr){
        if(curr->data == key){
            std::cout << key << " exists in doubly linked list\n";
            return;
        }
        curr = curr->next;
    }
    std::cout << key << " does not exist in doubly linked list\n";
}


int main(){
    Node* head = nullptr;
    insert_at_begg(head,3);
    insert_at_begg(head,2);
    insert_at_begg(head,1);
    insert_at_end(head,4);
    insert_at_end(head,5);
    insert_at_pos(head,3,10);

    traverse_fwd_rec(head);

    del_from_begg(head);
    del_from_end(head);
    del_at_pos(head,3);
    traverse_fwd_itr(head);

    search_val(head,10);
    search_val(head,3);

    std::cout << "Backward Traversal: ";
    traverse_bwd_itr(head);

    del_list(head);
    traverse_fwd_itr(head);
    return 0;
}
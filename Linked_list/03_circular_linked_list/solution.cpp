// The last pointer is used to ensure the O(1) time complexity for insertion at end. Otherwise, it would take O(n) to traverse and insert at end.

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

// Traversal of list
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


// Insertion at the beginning
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

// Insertion at end
void insert_at_end(Node* &last, int val){
    if(last == nullptr){
        Node* node = new Node(val);
        last = node;
        last->next = last;
        return;
    }

    Node* node = new Node(val);
    node->next = last->next;
    last->next = node;
    last = node;
}

// Insertion at specific position
void insert_at_pos(Node* &last, int pos, int val){
    if(pos < 1) return;

    if(pos == 1){
        insert_at_begg(last,val);
        return;
    }

    Node* curr = last->next;
    for(int i = 1; i < pos-1; i++){
        if(i != 1 && curr == last->next) break;
        curr = curr->next;
    }

    if(curr == last->next) return;

    if(curr == last){
        insert_at_end(last,val);
        return;
    }

    Node* node = new Node(val);
    node->next = curr->next;
    curr->next = node;
}


// Deletion from beginning
void del_from_begg(Node* &last){
    if(last == nullptr) return;

    if(last->next == last){
        delete last;
        last = nullptr;
        return;
    }

    Node* temp = last->next;
    last->next = temp->next;
    delete temp;
}

// deletion at end
void del_at_end(Node* &last){
    if(last == nullptr) return;

    if(last->next == last){
        delete last;
        last = nullptr;
        return;
    }

    Node* curr = last->next;
    while(curr->next != last) curr = curr->next;

    curr->next = last->next;
    delete last;
    last = curr;
}

// Deletion at specific position
void del_at_pos(Node* &last, int pos){
    if(pos < 1) return;

    if(pos == 1){
        del_from_begg(last);
        return;
    }

    Node* curr = last->next;
    for(int i = 1; i < pos-1; i++){
        if(i != 1 && curr == last->next) break;
        curr = curr->next;
    }

    if(curr == last->next || curr == last) return;

    if(curr->next == last){
        del_at_end(last);
        return;
    }

    Node* temp = curr->next;
    curr->next = temp->next;
    delete temp;
}


// Deletion of complete list
void del_list(Node* &last){
    if(last == nullptr) return;

    while(last) del_from_begg(last);
}


// Searching for value in list
void search_val(Node* &last, int key){
    if(last == nullptr) return;

    Node* curr = last->next;
    while(true){
        if(curr->data == key){
            std::cout << key << " exists in a linked list\n";
            break;
        }
        curr = curr->next;
        if(curr == last->next){
            std::cout << key << " does not exist in a linked list\n";
            break;
        }
    }
}


int main(){
    Node* last = nullptr;
    insert_at_begg(last,3);
    insert_at_begg(last,2);
    insert_at_begg(last,1);
    insert_at_end(last,4);
    insert_at_end(last,5);
    insert_at_pos(last,4,100);

    traverse(last);

    del_from_begg(last);
    del_at_end(last);
    del_at_pos(last,3);

    traverse(last);

    search_val(last,3);
    search_val(last,100);

    del_list(last);
    traverse(last);
    return 0;
}
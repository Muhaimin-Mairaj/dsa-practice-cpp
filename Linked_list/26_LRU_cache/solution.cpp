#include <iostream>
#include <unordered_map>

struct Node{
    int key, value;
    Node* prev;
    Node* next;
    Node(int key, int value);
};

void insert_at_begg(Node* &head, Node* &tail, int key, int val);
void del_from_end(Node* &head, Node* &tail);
void del_btwn(Node* &curr);

// I have manually handeled the doubly linked list and its functions. Although std::list can also be used.
class LRUCache{
private:
    int size;
    std::unordered_map<int , Node*> mp;
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    LRUCache(int cap) : size(cap) {}

    int get(int key){
        if(mp.find(key) != mp.end()){
            if(mp[key] == tail) del_from_end(head, tail);
            else if(mp[key] != head) del_btwn(mp[key]);
            if(mp[key] != head) insert_at_begg(head,tail,key,mp[key]->value);
            return head->value; 
        }
        else return -1;
    }

    void put(int key, int val){
        if(mp.find(key) != mp.end()){
            mp[key]->value = val;
            return;
        }
        if(size == count){
            mp.erase(tail->key);
            del_from_end(head,tail);
            count--;
        }
        insert_at_begg(head,tail,key,val);
        mp.insert({key,head});
        count++;
    }

    ~LRUCache(){
        while(head){
            Node* temp = head->next;
            delete head;
            head = temp;
        }
    }
};


int main(){
    LRUCache cache(2);
    cache.put(1,1);
    cache.put(2,2);
    std::cout << cache.get(1) << std::endl;
    cache.put(3,3);
    std::cout << cache.get(2) << std::endl; 
    cache.put(4,4);
    std::cout << cache.get(1) << std::endl;
    std::cout << cache.get(3) << std::endl;
    std::cout << cache.get(4) << std::endl;
    return 0;
}




void insert_at_begg(Node* &head, Node* &tail, int key, int val){
    Node* node = new Node(key, val);

    if(head == nullptr){
        head = node;
        tail = node;
        return;
    }

    node->next = head;
    head->prev = node;
    head = node;
}


Node::Node(int key, int value){
    this->key = key;
    this->value = value;
    prev = next = nullptr;
}


void del_from_end(Node* &head, Node* &tail){
    if(tail == nullptr) return;

    if(head->next == nullptr){
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    tail->prev->next = nullptr;
    Node* temp = tail->prev;
    delete tail;
    tail = temp;
}


void del_btwn(Node* &curr){
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev;
    delete curr;
}

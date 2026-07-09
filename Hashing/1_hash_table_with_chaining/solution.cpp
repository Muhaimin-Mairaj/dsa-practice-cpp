#include <iostream>
#include <vector>

struct Node{
    int key, value;
    Node* next;
    Node(int key, int value){
        this->key = key;
        this->value = value;
        next = nullptr;
    }
};

class HashMap{
private:
    int size, capacity;
    std::vector<Node*> mp;
    double DEFAULT_LOAD_FACTOR = 0.75;

    int getIdx(int key){
        key = std::hash<int>()(key);
        return key % size;
    }

public:
    HashMap(int size){
        this->size = size;
        mp.resize(size);
        capacity = 0;

        for(int i = 0; i < mp.size(); i++) mp[i] = nullptr;
    }

    void insert(int key, int value){
        if(double(capacity)/size > 0.75){
            printMap();
            rehash();
        }

        int idx = getIdx(key);

        Node* head = mp[idx];
        while(head){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = mp[idx];
        Node* node = new Node(key,value);
        node->next = head;
        mp[idx] = node;
        capacity++;
    }

    void del(int key){
        int idx = getIdx(key);

        Node* head = mp[idx];
        Node* prev = nullptr;
        while(head){
            if(head->key == key){
                std::cout << key << "-" << head->value << " deleted successfully\n";

                Node* next = head->next;
                if(prev) prev->next = next;
                else mp[idx] = next;
                delete head;

                capacity--;
                return;
            }
            prev = head;
            head = head->next;
        }
        std::cout << "-1\n";
    }

    void search(int key){
        int idx = getIdx(key);

        Node* head = mp[idx];
        while(head){
            if(head->key == key){
                std::cout << key << "-" << head->value << " exists\n";
                return;
            }
            head = head->next;
        }
        std::cout << key << " does not exists\n";
    }

    void rehash(){
        std::cout << "\n===== Rehashing Done =====\n";
        std::vector<Node*> temp = mp;
        mp.resize(2*size);
        for(int i = 0; i < mp.size(); i++) mp[i] = nullptr;
        size *= 2;
        
        for(int i = 0; i < temp.size(); i++){
            Node* head = temp[i];
            while(head){
                int newIdx = getIdx(head->key);
                Node* next = head->next;
                head->next = mp[newIdx];
                mp[newIdx] = head;
                head = next;
            }
        }
    }

    void printMap(){
        for(int i = 0; i < mp.size(); i++){
            Node* head = mp[i];
            std::cout << i;
            while(head){
                std::cout << " --> " << head->key << "-" << head->value;
                head = head->next;
            }
            std::cout << std::endl;
        }
    }

    ~HashMap(){
        for(int i = 0; i < mp.size(); i++){
            Node* head = mp[i];
            while(head){
                Node* next = head->next;
                delete head;
                head = next;
            }
        }
    }
};


int main(){
    HashMap mp(5);
    mp.insert(4,40);
    mp.insert(2,20);
    mp.insert(9,140);
    mp.insert(3,30);
    mp.insert(23,230);
    mp.insert(9,100);
    
    mp.del(3);
    mp.search(3 );
    mp.printMap();
    return 0;
}
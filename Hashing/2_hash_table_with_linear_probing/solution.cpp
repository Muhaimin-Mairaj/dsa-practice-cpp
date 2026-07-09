#include <iostream>
#include <vector>

struct Node{
    int key, value;
    Node(int key, int value){
        this->key = key;
        this->value = value;
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
        mp.resize(size, nullptr);
        capacity = 0;

    }

    void insert(int key, int value){
        if(double(capacity)/size > 0.75){
            printMap();
            rehash();
        }
        int idx = getIdx(key);

        while(mp[idx] != nullptr && mp[idx]->key != key && mp[idx]->key != -1) idx = (idx + 1) % size;

        if(mp[idx] == nullptr || mp[idx]->key == -1){
            mp[idx] = new Node(key, value);
            capacity++;
        }
        else mp[idx]->value = value;
    }

    void del(int key){
        int idx = getIdx(key);
        int counter = 0;

        while(mp[idx]->key != key){
            idx = (idx + 1) % size;
            if(counter++ > size){
                std::cout << "-1\n";
                return;
            }
        }
        mp[idx] = new Node(-1, -1);
        capacity--;
    }

    void search(int key){
        int idx = getIdx(key);
        int counter = 0;
    
        while(mp[idx] && counter < size){
            if(mp[idx]->key == key){
                std::cout << "(" << key << ", " << mp[idx]->value << ") exists\n";
                return;
            }
            idx = (idx + 1) % size;
            counter++;
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
            if(temp[i] && temp[i]->key != -1){
                int newIdx = getIdx(temp[i]->key);
                while(mp[newIdx] != nullptr && mp[newIdx]->key != -1) newIdx = (newIdx + 1) % size;
                mp[newIdx] = temp[i];
            }
        }
    }

    void printMap(){
        for(int i = 0; i < mp.size(); i++){
            std::cout << i;
            if(mp[i]) std::cout << " --> (" << mp[i]->key << ", " << mp[i]->value << ")";
            std::cout << std::endl;
        }
    }

    ~HashMap(){
        for(int i = 0; i < mp.size(); i++){
            delete mp[i];
            mp[i] = nullptr;
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
    mp.insert(33,100);

    mp.del(3);
    mp.search(33);
    mp.printMap();
    return 0;
}
#include <iostream>

class Browser{
private:
    struct Node{
        std::string data;
        Node* prev, *next;

        Node(std::string url){
            data = url;
            prev = next = nullptr;
        }
    };
    Node* curr = nullptr;

public:
    Browser(std::string page){
        curr = new Node(page);
    }

    void visit(std::string url){
    Node* node = new Node(url);

    curr->next = node;
    node->prev = curr;
    curr = node;
    }

    void forward(int steps){
        for(int i = 1; i <= steps && curr->next != nullptr; i++) curr = curr->next;
        std::cout << curr->data << std::endl;
    }

    void back(int steps){
        for(int i = steps; i > 0 && curr->prev != nullptr; i--) curr = curr->prev;
        std::cout << curr->data << std::endl;
    }

    ~Browser(){
        while(curr->prev != nullptr) curr = curr->prev;
        while(curr){
            Node* temp = curr->next;
            delete curr;
            curr = temp;
        }
    }

};





int main(){
    Browser obj("github.com");
    obj.visit("google.com");
    obj.visit("freecodecamp.org");
    obj.visit("youtube.com");
    obj.back(1);
    obj.back(1);
    obj.forward(1);
    obj.visit("linkedin.com");
    obj.forward(2);
    obj.back(2);
    obj.back(7);

    return 0;
}



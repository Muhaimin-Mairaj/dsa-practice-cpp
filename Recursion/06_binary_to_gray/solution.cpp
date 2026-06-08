#include <iostream>

// This solution runs in O( log bin ) time complexity

int gray_code(int bin){
    if (bin/10 == 0){
        std::cout << bin;
        return bin;
    }

    int curr = bin % 10;
    std::cout << (gray_code(bin/10) ^ curr);
    return curr;
}

int main(){
    gray_code(1001);
    std::cout << std::endl;
    gray_code(11);
    return 0;
}
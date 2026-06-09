#include <iostream>

// This solution runs in O(2^n) time complexity

void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod){
    if(n == 1){
        std::cout << "Disk 1 moved from " << from_rod << " to "<< to_rod << std::endl;
        return;
    }

    towerOfHanoi(n-1, from_rod , aux_rod, to_rod);
    std::cout << "Disk "<< n <<" moved from " << from_rod << " to "<< to_rod << std::endl;
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}


int main(){
    int n = 3;

    towerOfHanoi(n ,'A' , 'C', 'B');
    return 0;
}

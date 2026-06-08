#include <iostream>
#include <vector>

// This solution runs in O( 2^sum ) time complexity

int rec_coin(std::vector<int> &coins, int i, int sum){
    if (sum == 0) return 1;

    if (sum < 0 || i == coins.size()) return 0;

    return rec_coin(coins, i, sum - coins[i]) + rec_coin(coins, i+1, sum);
}



int main(){
    std::vector<int> v = {1,2,3};
    std::cout << rec_coin(v, 0, 4) << std::endl;

    std::vector<int> v2 = {2,5,3,6};
    std::cout << rec_coin(v2, 0, 10) << std::endl;
    return 0;
}
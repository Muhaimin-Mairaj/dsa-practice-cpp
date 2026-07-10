#include <iostream>
#include <unordered_map>
#include <vector>

// This solution runs in O(n) time and space complexity. 
// Although it can be solved in O(1) space through nested loops, but then time complexity will be O(n^2)
int maxDistance(std::vector<int> &v){
    std::unordered_map<int, int> mp;
    int ans = 0;

    for(int i = 0; i < v.size(); i++){
        if(mp.find(v[i]) != mp.end()) ans = std::max(ans, i - mp[v[i]]);
        else mp.insert({v[i], i});
    }
    return ans;
}

int main(){
    std::vector<int> v = {3,2,1,2,1,4,5,8,6,7,4,2};
    std::cout << maxDistance(v);
    return 0;
}
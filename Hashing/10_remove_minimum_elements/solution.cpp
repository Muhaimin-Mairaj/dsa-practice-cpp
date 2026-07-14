#include <iostream>
#include <unordered_map>
#include <vector>

// This solution runs in O(n + m) time and space complexity
int removeMinimumElements(std::vector<int> &v1, std::vector<int> &v2){
    std::unordered_map<int, std::pair<int,int>> mp;
    int ans = 0;
    
    for(int i = 0; i < v1.size(); i++) mp[v1[i]].first++;
    for(int i = 0; i < v2.size(); i++) mp[v2[i]].second++;

    for(auto &it : mp){
        ans += std::min(it.second.first, it.second.second);
    }
    return ans;
}


int main(){
    std::vector<int> v1 = {4,2,4,4};
    std::vector<int> v2 = {4,3,4};
    std::cout << removeMinimumElements(v1,v2);
    return 0;
}
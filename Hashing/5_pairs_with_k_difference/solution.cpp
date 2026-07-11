#include <iostream>
#include <unordered_map>
#include <vector>

// This solution runs in O(n) time and space complexity
int pairsWithDiffernceK(std::vector<int> &v, int k){
    std::unordered_map<int, int> mp;
    int ans = 0;

    for(int i = 0; i < v.size(); i++){
        int cmp1 = v[i] - k;
        int cmp2 = v[i] + k;

        if(mp.find(cmp1) != mp.end()) ans += mp[cmp1];
        if(mp.find(cmp2) != mp.end()) ans += mp[cmp2];
        mp[v[i]]++;
    }
    return ans;
}


int main(){
    std::vector<int> v = {8,16,12,16,4,0};
    std::cout << pairsWithDiffernceK(v,4);
    return 0;
}
#include <iostream>
#include <unordered_map>
#include <vector>
#include <numeric>

// Custom hash function because std::pair does not have by default
struct pair_hash{
    size_t operator()(const std::pair<int,int> &p) const{
        return std::hash<long long>()(((long long)p.first << 32) ^ p.second);
    }
};

// This solution runs in O(n^2 * logn) time and O(n) space complexity
int maxPointsOnLine(std::vector<std::pair<int, int>> &v){
    int finalMax = 0, currMax = 0;
    std::unordered_map<std::pair<int,int>, int, pair_hash> mp;
    std::pair<int, int> slope;

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v.size(); j++){
            if (i == j) continue;

            slope.first = v[j].second - v[i].second;
            slope.second = v[j].first - v[i].first;
            int div = std::gcd(slope.first, slope.second);
            div = (slope.first < 0 && slope.second < 0)? -div : div;

            if(div != 0){
                slope.first /= div;
                slope.second /= div;
            }
            slope.first = (slope.second < 0)? (-slope.second, -slope.first) : slope.first;
            currMax = std::max(currMax, ++mp[slope]);
        }
        finalMax = std::max(currMax+1,finalMax);
        mp.clear();
    }
    return finalMax;
}


int main(){
    std::vector<std::pair<int, int>> v = {{-1,1}, {0,0}, {1,1}, {2,2}, {3,3}, {3,4}};
    std::cout << maxPointsOnLine(v);
    return 0;
}
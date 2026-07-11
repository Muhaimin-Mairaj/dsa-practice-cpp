#include <iostream>
#include <unordered_set>
#include <vector>

// 1st Approach: Using HashSet (O(n) time and space complexity)
int repetitiveElementSet(std::vector<int> &v){
    std::unordered_set<int> st;

    for(int i = 0; i < v.size(); i++){
        if(st.find(v[i]) != st.end()) return v[i];
        st.insert(v[i]);
    }
    return -1;
}

// 2nd Approach: Using Sum Formula (O(n) time and O(1) space complexity)
int repetitiveElementFormula(std::vector<int> &v){
    int n = v.size(), sum = 0, totalSum = (n*(n+1))/2; 

    for(int i = 0; i < n; i++){
        sum += v[i];
    }
    return n + sum - totalSum;
}

int main(){
    std::vector<int> v = {1,5,1,2,3,4};
    std::cout << repetitiveElementSet(v) << std::endl;
    std::cout << repetitiveElementFormula(v);
    return 0;
}
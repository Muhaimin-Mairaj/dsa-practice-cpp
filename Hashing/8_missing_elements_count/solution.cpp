#include <iostream>
#include <unordered_set>
#include <vector>

// This solution runs in O(n) time and space complexity
int missingElementCount(std::vector<int> &v){
    std::unordered_set<int> st;
    int min = v[0], max = 0;

    for(int i = 0; i < v.size(); i++){
        st.insert(v[i]);
        if(v[i] < min) min = v[i];
        if(v[i] > max) max = v[i];
    }
    return (max - min + 1) - st.size();
}

int main(){
    std::vector<int> v = {4,5,3,8,4};
    std::cout << missingElementCount(v);
    return 0;
}
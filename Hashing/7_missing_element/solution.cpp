#include <iostream>
#include <unordered_set>
#include <vector>

// This solution runs in O(n + high - low + 1) time and O(n) space complexity
void missingElementsInRange(std::vector<int> &v, int low, int high){
    std::unordered_set<int> st;
    for(int i = 0; i < v.size(); i++) st.insert(v[i]);

    for(int i = low; i <= high; i++){
        if(st.find(i) == st.end()) std::cout << i << " ";
    }
}

int main(){
    std::vector<int> v = {1,14,11,51,15};
    missingElementsInRange(v,50,55);
    return 0;
}
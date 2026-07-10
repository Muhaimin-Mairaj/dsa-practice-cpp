#include <iostream>
#include <unordered_set>
#include <vector>

// This solution runs in O(n) time and O(k) space complexity
void duplicatesWithinK(std::vector<int> &v, int k){
    std::unordered_set<int> st;

    for(int i = 0; i < v.size(); i++){
        if(st.find(v[i]) != st.end()){
            std::cout << "Yes\n";
            return;
        }
        st.insert(v[i]);
        if(i >= k) st.erase(v[i - k]);
    }
    std::cout << "No\n";
}

int main(){
    std::vector<int> v = {1,2,3,1,4,5};
    duplicatesWithinK(v,3);
    return 0;
}
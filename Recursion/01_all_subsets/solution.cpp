#include <iostream>
#include <vector>

// This solution runs in O(n * 2^n) time complexity
void getAllSubsets(std::vector<int> nums, std::vector<int> &ans, int idx, std::vector<std::vector<int>> &subsets){
    if (idx == nums.size()){
        subsets.push_back({ans});
        return;
    }

    ans.push_back(nums[idx]);
    getAllSubsets(nums,ans,idx+1,subsets);

    ans.pop_back();
    getAllSubsets(nums,ans,idx+1,subsets);
}

void display(std::vector<std::vector<int>> &subsets){
    for (int i = 0; i < subsets.size(); i++){
        std::vector<int> temp = subsets[i];
        for (int val : temp){
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main(){
    std::vector<int> nums = {1,2,3};
    std::vector<int> ans;
    std::vector<std::vector<int>> subsets;

    getAllSubsets(nums,ans,0,subsets);
    display(subsets);
    return 0;
}
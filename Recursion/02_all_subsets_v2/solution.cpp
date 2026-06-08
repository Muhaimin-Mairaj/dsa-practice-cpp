#include <iostream>
#include <vector>

// This solution runs in O(n * 2^n) time complexity

void sortVector(std::vector<int> &nums){
    for(int i = 0; i < nums.size()-1; i++){
        for(int j = i+1; j > 0; j--){
            if(nums[j] < nums[j-1]){
                int temp = nums[j];
                nums[j] = nums[j-1];
                nums[j-1] = temp;
            }
            else break;
        }
    }
}

void getAllSubsets(std::vector<int> nums, std::vector<int> &ans, int idx, std::vector<std::vector<int>> &subsets){
    if (idx == nums.size()){
        subsets.push_back({ans});
        return;
    }

    ans.push_back(nums[idx]);
    getAllSubsets(nums,ans,idx+1,subsets);

    ans.pop_back();
    int temp_idx = idx+1;
    while (temp_idx < nums.size() && nums[temp_idx] == nums[temp_idx-1]){
        temp_idx++;
    }
    getAllSubsets(nums,ans,temp_idx,subsets);
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
    std::vector<int> nums = {1,2,2};
    std::vector<int> ans;
    std::vector<std::vector<int>> subsets;

    sortVector(nums);
    getAllSubsets(nums,ans,0,subsets);
    display(subsets);
    return 0;
}
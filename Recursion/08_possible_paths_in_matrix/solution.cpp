#include <iostream>
#include <vector>

// This solutions runs in O(2*(m*n)) time complexity. where m and n are dimensions of the matrix.

void all_Paths(std::vector<std::vector<int>> &mat, int i, int j, std::vector<int> &ans){
    if(i == mat.size()-1 && j == mat[0].size()-1 ){
        ans.push_back(mat[i][j]);
        for(int i : ans){
            std::cout << i << " ";
        }
        std::cout << std::endl;
        ans.pop_back();
        return;
    }

    if(i == mat.size() || j == mat[0].size()) return;

    ans.push_back(mat[i][j]);

    all_Paths(mat,i,j+1,ans);
    all_Paths(mat,i+1,j,ans);

    ans.pop_back();
}



int main(){
    std::vector<std::vector<int>> mat = { {1,2,3}, {4,5,6}};
    std::vector<int> ans;
    all_Paths(mat,0,0,ans);
    std::cout << std::endl;
    
    std::vector<std::vector<int>> mat2 = { {1,2}, {3,4} };
    std::vector<int> ans2;
    all_Paths(mat2,0,0,ans2);
    return 0;
}
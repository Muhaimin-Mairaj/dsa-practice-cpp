#include <iostream>
#include <vector>

bool isSafe(std::vector<std::string> &board, int row, int col, int n){
    for (int i = 0; i < n; i++){
        if(board[row][i] == 'Q') return false;
    }

    for (int i = 0; i < n; i++){
        if(board[i][col] == 'Q') return false;
    }
 
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j-- ){
        if(board[i][j] == 'Q') return false;
    }

    for (int i = row, j = col; i >= 0 && j < n; i--, j++ ){
        if(board[i][j] == 'Q') return false;
    }

    return true;
    std::cout << "debug here\n"; 
    
}

void nQueens(std::vector<std::string> &board, int row, int n, std::vector<std::vector<std::string>> &ans ){
    if(row == n){
        ans.push_back({board});
        return;
    }

    for (int j = 0; j < n; j++){
        if(isSafe(board,row,j,n)){
            board[row][j] = 'Q';
            nQueens(board,row+1,n,ans);
            board[row][j] = '.';
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n){
    std::vector<std::string> board(n, std::string(n,'.'));
    std::vector<std::vector<std::string>> ans;

    nQueens(board,0,n,ans);
    return ans;
}

void display(std::vector<std::vector<std::string>> &ans){
    for (int i = 0; i < ans.size(); i++){
        std::vector<std::string> temp = ans[i];
        for (std::string val : temp){
            std::cout << val << std::endl;
        }
        std::cout << "\n\n";
    }
}

int main(){
    std::vector<std::vector<std::string>> ans = solveNQueens(4);
    display(ans);

    return 0;
}
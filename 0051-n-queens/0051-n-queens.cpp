class Solution {
public:
    bool isSafe(int row, int col,int n, vector<string>&board) {
        for(int i =0;i<n;i++) {
            if(board[i][col] == 'Q') return false;
        }
        for(int j = 0;j<n;j++) {
            if(board[row][j] == 'Q') return false;
        }
        for(int i = row-1, j = col-1;i>=0&&j>=0;i--,j--) {
            if(board[i][j] == 'Q') return false;
        }
        for(int i = row-1, j = col+1;i>=0&&j<n;i--,j++) {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void helper(vector<vector<string>>&ans, vector<string>&board,int n, int row) {
        if(row == n) {
            ans.push_back(board);
            return;
        }
        for(int col = 0;col<n;col++) {
            if(isSafe(row,col,n,board)) {
                board[row][col] = 'Q';
                helper(ans,board,n,row+1);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        helper(ans,board,n,0);
        return ans;
    }
};
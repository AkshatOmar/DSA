class Solution {
public:
    bool isValid(vector<string>&board, int row,int col,int n) {
        if(row<0 ||col<0||row>=n||col>=n)return false;
        // check column
        for(int j =0;j<n;j++) {
            if(board[row][j] == 'Q') return false;
        }
        //check row
        for(int i = 0;i<n;i++) {
            if(board[i][col] == 'Q') return false;
        }
        // left diagonal
        for(int i = row, j = col;i>=0&&j>=0;i--,j--) {
            if(board[i][j] == 'Q') return false;
        }
        // right Diagonal
        for(int i = row,j = col;i>=0&&j<n;i--,j++) {
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    void helper(vector<string>&board,vector<vector<string>>&res, int row,int n) {
        if(row == n) {
            res.push_back(board);
            return;
        }
        for(int col = 0;col<n;col++) {
            if(isValid(board,row,col,n)) { 
                board[row][col] = 'Q';
                helper(board,res,row+1,n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>board(n,string(n,'.'));
        helper(board,res,0,n);
        return res;
    }
};
class Solution {
public:
    bool isValid(vector<vector<char>>&board, char c, int row, int col) {
        // not in row & col
        for(int i = 0;i<9;i++) {
            if(board[row][i] == c) return false;
            if(board[i][col] == c) return false;
        }
        // not in 3x3 grid
        // how to know which grid is this out of 9 3x3 grids
        int startRow = row/3*3;
        int startCol = col/3*3;
        for(int i = 0;i<3;i++) {
            for(int j = 0;j<3;j++) {
                if(board[startRow+i][startCol+j] == c) return false;
            }
        }
        return true;
    }
    bool helper(vector<vector<char>>&board) {
        for(int row = 0; row<9;row++) {
            for(int col = 0;col<9;col++) {
                if(board[row][col] == '.'){
                    for( char c = '1'; c<='9'; c++) {
                        if(isValid(board, c, row,col)){
                            board[row][col] = c;
                            if(helper(board))return true;
                            board[row][col] = '.';
                        }
                        
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        helper(board);
         
    }
};
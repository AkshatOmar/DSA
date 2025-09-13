class Solution {
public:
    vector<vector<int>>move{{1,0},{-1,0},{0,1},{0,-1}};
    bool helper(vector<vector<char>>&board, string &word,int idx,int n,int m,int i,int j) {
        if(idx == word.size()) {
            return true;
        }
        if(i<0||j<0||i>=m||j>=n||board[i][j] == '#')return false;
        if(board[i][j]!=word[idx]) return false;
        char temp = board[i][j];
        board[i][j] = '#';
        for(int k = 0;k<4;k++) {
            int newI = i+move[k][0];
            int newJ = j+move[k][1];
            if(helper(board,word,idx+1,n,m,newI,newJ)){
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(board[i][j] == word[0]) {
                    if(helper(board, word, 0,n,m,i,j)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
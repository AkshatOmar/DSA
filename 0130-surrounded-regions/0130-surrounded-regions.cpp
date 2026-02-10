class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>& board, vector<vector<int>>&vis,int i,int j,int n,int m) {
        vis[i][j] = 1;
        for(auto &dir : directions) {
            int new_i = i+dir[0];
            int new_j = j+ dir[1];
            if(new_i >= 0 && new_j >= 0 && new_i<n && new_j<m && vis[new_i][new_j] ==0 && board[new_i][new_j] == 'O') {
                dfs(board,vis,new_i,new_j,n,m);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i = 0;i<n;i++) {
            if(board[i][0] == 'O') {
                dfs(board,vis,i,0,n,m);
            }
        }
        for(int i = 0;i<m;i++) {
            if(board[0][i] == 'O') {
                dfs(board,vis,0,i,n,m);
            }
        }
        for(int i = 0;i<m;i++) {
            if(board[n-1][i] == 'O') {
                dfs(board,vis,n-1,i,n,m);
            }
        }
        for(int i = 0;i<n;i++) {
            if(board[i][m-1] == 'O') {
                dfs(board,vis,i,m-1,n,m);
            }
        }
        for(int i =0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(vis[i][j] == 0 && board[i][j]=='O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
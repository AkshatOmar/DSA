class Solution {
public:
    int n,m;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>&grid,int i, int j) {
        grid[i][j] = 0;
        for(auto &dir : directions) {
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && grid[new_i][new_j]==1) {
                dfs(grid,new_i,new_j);
            }
        }
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i = 0;i<n;i++) {
            if(grid[i][0] == 1) {
                dfs(grid,i,0);
            }
            if(grid[i][m-1] == 1) {
                dfs(grid,i,m-1);
            }
        }
        for(int i = 0;i<m;i++) {
            if(grid[0][i] == 1) {
                dfs(grid,0,i);
            }
            if(grid[n-1][i] == 1) {
                dfs(grid,n-1,i);
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        return  cnt;
    }
};
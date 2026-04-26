class Solution {
public:
    int n,m;
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    bool dfs(vector<vector<char>>&grid, int i, int j, int pi, int pj,vector<vector<bool>>&vis) {
        vis[i][j] = true;
        for(auto &dir : directions) {
            int new_i = dir[0] + i;
            int new_j = dir[1] + j;
            if(new_i >=0 && new_j >=0 && new_i < n && new_j < m) {
                if(grid[i][j] == grid[new_i][new_j]) {
                    
                    if(!vis[new_i][new_j]) {
                        if(dfs(grid,new_i,new_j,i,j,vis)) return true;
                    }
                    else if(vis[new_i][new_j] == true && new_i != pi || new_j != pj) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(!vis[i][j]) {
                    if(dfs(grid,i,j,-1,-1,vis)) return true;
                }
            }
        }
        return false;
    }
};
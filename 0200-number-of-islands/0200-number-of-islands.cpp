class Solution {
public:
    vector<vector<int>>directions{{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(vector<vector<char>>&grid, int i, int j, int n, int m) {
        grid[i][j] = '#';
        for(auto &dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            if(new_i >= 0 && new_j >= 0 && new_i < n && new_j < m && grid[new_i][new_j] != '#') {

                if(grid[new_i][new_j] == '1') {
                    dfs(grid,new_i,new_j,n,m);
                }

            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int islands = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == '1') {
                    dfs(grid,i,j,n,m);
                    islands++;
                }
            }
        }    
        return islands;
    }
};
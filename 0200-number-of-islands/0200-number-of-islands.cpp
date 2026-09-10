class Solution {
public:
int n,m;
    vector<vector<int>>directions{{-1,0},{0,-1},{0,1},{1,0}};
    void dfs(vector<vector<char>>&grid, int i,int j) {
        grid[i][j] = '#';
        for(auto &dir : directions) {
            int new_i = dir[0]+i;
            int new_j = dir[1]+j;
            if(new_i>=0 && new_j >=0 && new_i <n &&new_j <m && grid[new_i][new_j] == '1' && grid[new_i][new_j] != '#') {
                dfs(grid,new_i,new_j);
            }
            
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
         n = grid.size();
         m = grid[0].size();
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == '1') {
                    islands++;
                    dfs(grid,i,j);
                    
                }
                
            }
        }
        
        return islands;
    }
};
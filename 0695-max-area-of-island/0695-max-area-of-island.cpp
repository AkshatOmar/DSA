class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(vector<vector<int>>&grid, int i, int j, int n, int m) {

        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != 1) {
            return 0;
        }
        grid[i][j] = 2;
        return 1+ dfs(grid,i-1,j,n,m)+dfs(grid,i+1,j,n,m)+dfs(grid,i,j-1,n,m)+dfs(grid,i,j+1,n,m);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int maxArea = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 1) {
                    maxArea = max(dfs(grid,i,j,n,m),maxArea);
                }
            }
        }
        return maxArea;
    }
};
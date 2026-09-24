class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<int>>&grid, int i, int j , int n, int m, int &area) {
        
        for(auto &dir:directions) {
            int new_i = dir[0]+i;
            int new_j = dir[1]+j;
            if(new_i>=0 && new_j >= 0 && new_i <n && new_j<m && grid[new_i][new_j] == 1) {
                area++;
                grid[new_i][new_j] = -1;
                dfs(grid,new_i, new_j,n,m,area);
            }
        }
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int area = 0;
        int maxArea = 0;
        for(int  i =0 ;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 1) {
                   grid[i][j] = -1;
                   dfs(grid,i,j,n,m,area);
                    maxArea = max(maxArea, area+1);
                    area = 0;
                }
            }
        }

        return maxArea;
    }
};
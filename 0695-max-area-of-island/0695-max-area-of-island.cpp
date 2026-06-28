class Solution {
public:
vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1}};
    int dfs(vector<vector<int>>&grid,int i, int j, int n, int m) {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0) {
            return 0;
        }
        
        grid[i][j] = 0;
        int area= 1;
        for(auto &dir: directions) {
            area+=dfs(grid,dir[0]+i,dir[1]+j,n,m);
        }
        return area;
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
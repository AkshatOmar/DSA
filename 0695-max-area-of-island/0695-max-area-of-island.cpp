class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    int dfs(vector<vector<int>>&grid, int i, int j , int n, int m) {
        int area = 1;
        grid[i][j] = -1;
        for(auto &dir:directions) {
            int new_i = dir[0]+i;
            int new_j = dir[1]+j;
            if(new_i>=0 && new_j >= 0 && new_i <n && new_j<m && grid[new_i][new_j] == 1) {
                
                area += dfs(grid,new_i, new_j,n,m);
            }
        }
        return area;
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
                    maxArea = max(maxArea, dfs(grid,i,j,n,m));
                }
            }
        }
        for(int  i =0 ;i<n;i++) {
            for(int j = 0;j<m;j++) {
                cout<<grid[i][j]<<" ";
            }
            cout<< endl;
        }
        return maxArea;
    }
};
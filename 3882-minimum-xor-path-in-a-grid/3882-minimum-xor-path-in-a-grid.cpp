class Solution {
public:
    int fun(int i, int j, vector<vector<int>>&grid, int curr) {
        if(i<0 || j<0) return INT_MAX;
        curr ^= grid[i][j];
        if(i == 0 && j == 0) return curr;

        int up = fun(i-1,j,grid,curr);
        int left = fun(i,j-1, grid, curr);
        return min(up, left);
    }
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return fun(n-1, m-1, grid, 0);
    }
};
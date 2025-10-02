class Solution {
public:
    long helper(vector<vector<int>>& grid,int m, int n,vector<vector<int>>&dp) {
        if(m == 0 && n == 0) return dp[0][0] = grid[0][0];
        if(m<0 || n <0) return INT_MAX;
        if(dp[m][n] != -1) return dp[m][n];
        long up = grid[m][n]+helper(grid,m-1,n,dp);
        long left = grid[m][n]+helper(grid,m,n-1,dp);
        return dp[m][n] = min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return helper(grid,m-1,n-1,dp);
    }
};
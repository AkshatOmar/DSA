class Solution {
public:
    int helper(vector<vector<int>>&grid,int k, int i, int j,vector<vector<vector<int>>>&dp) {
        if(i == 0 && j == 0) {
            if(grid[i][j] == 0) return 0;
            else if(k>=1) return grid[0][0];
            else return -1e9;
        }
        if(i < 0 || j < 0 || k < 0) return -1e9;
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int cost = grid[i][j] == 0 ? 0 : 1;
        int down = -1e9, right = -1e9;
        if(k>=cost){
            if(i>0)down = grid[i][j] + helper(grid,k-cost,i-1,j,dp);
            if(j>0)right = grid[i][j] + helper(grid,k-cost,i,j-1,dp);
        }

        return dp[i][j][k] = max(down,right);
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int res = helper(grid,k,n-1,m-1,dp);
        if(res < 0) return -1;
        return res;
    }
};
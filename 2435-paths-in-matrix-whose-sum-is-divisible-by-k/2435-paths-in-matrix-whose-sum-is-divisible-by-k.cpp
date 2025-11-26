class Solution {
public:
    const int MOD = 1e9 + 7;
    int helper(vector<vector<int>>&grid, int k, int i,int j, int rem,vector<vector<vector<int>>>&dp)  {
        if(i<0 || j<0) return 0;
        rem = (rem+grid[i][j]) %k;
        if(i == 0 && j == 0) {
            return (rem == 0);
        }
        if(dp[i][j][rem]!= -1) return dp[i][j][rem];
        int up = helper(grid,k,i-1,j,rem,dp);
        int left = helper(grid,k,i,j-1,rem,dp);
        long long ans = (up+left)%MOD;
        return dp[i][j][rem] = (int) ans;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        return helper(grid,k,n-1,m-1,0,dp);
    }
};
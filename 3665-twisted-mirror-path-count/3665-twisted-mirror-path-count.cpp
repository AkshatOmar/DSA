class Solution {
public:
    //dir = 0 => coming from left
    //dir = 1 => coming from up
    int helper(vector<vector<int>>&grid, int n, int m, int i, int j, int dir,vector<vector<vector<long long>>>&dp) {
        if(i == n-1 && j == m-1) return 1;
        if(i<0 || j<0 || i>=n || j>=m) return 0;
        if(dp[i][j][dir] != -1) return dp[i][j][dir];
        if(grid[i][j] == 1) {
            if(dir == 0) {
                // forcefully move to down
                dp[i][j][dir] = helper(grid,n,m,i+1,j,1,dp);
            }
            else {
                //forcefully move right;
                dp[i][j][dir] = helper(grid,n,m,i,j+1,0,dp);
            }
            
        }
        else {
            // can move either down or right;
            dp[i][j][dir] = (helper(grid,n,m,i+1,j,1,dp) + helper(grid,n,m,i,j+1,0,dp)) % 1000000007;
        }
        return dp[i][j][dir];
    }
    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<long long>>>dp(n,vector<vector<long long>>(m,vector<long long>(2,-1)));
        return helper(grid,n,m,0,0,0,dp);
    }
};
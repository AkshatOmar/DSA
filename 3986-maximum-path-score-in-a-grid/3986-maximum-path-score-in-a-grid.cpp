class Solution {
public:
    int helper(vector<vector<int>>&grid,int i,int j, int k,vector<vector<vector<int>>>&dp) { 
        //base cases
        if(i<0 ||j<0||k<0) return -1e9;
        if(i == 0 && j==0) {
            if(grid[0][0] == 0) return 0;
            else if(k>=1) return grid[0][0];
            else return -1e9;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];
        int right = -1e9;
        int up = -1e9;
        //for 0 cost will be same.
        int cost = grid[i][j] == 0 ? 0 : 1;
        if(k>=cost) {
            //explore up
            if(i>0) up = grid[i][j]+ helper(grid,i-1,j,k-cost,dp);
            //explore right
            if(j>0) right =grid[i][j]+ helper(grid,i,j-1,k-cost,dp);
        }
        return dp[i][j][k] = max(right,up);

    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int res = helper(grid,n-1,m-1,k,dp);
        if(res<0) return -1;
        else return res;
    }
};
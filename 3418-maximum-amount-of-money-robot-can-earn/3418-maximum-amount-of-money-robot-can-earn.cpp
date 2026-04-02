class Solution {
public:
    int helper(int i, int j, vector<vector<int>>&coins, int k,vector<vector<vector<int>>>&dp) {
        if(i == 0 && j == 0){
            if(coins[i][j] < 0) {
                if(k<2) {
                    return 0;
                }
            }
            return coins[i][j];
        }

        if(i<0 || j<0) return -1e7;

        if(dp[i][j][k] != INT_MIN) return dp[i][j][k];

        int left = -1e7;
        if(coins[i][j] < 0) {
            if(k<2) {
                left = max(helper(i,j-1,coins,k+1,dp), coins[i][j] + helper(i,j-1,coins,k,dp));
            }
            else {
                left = coins[i][j] + helper(i,j-1,coins,k,dp);
            }
        }
        else {
            left = coins[i][j] + helper(i,j-1,coins,k,dp);
        }

        int up = -1e7;
        if(coins[i][j] < 0) {
            if(k<2) {
                up = max(helper(i-1,j,coins,k+1,dp), coins[i][j] + helper(i-1,j,coins,k,dp));
            }
            else {
                up = coins[i][j] + helper(i-1,j,coins,k,dp);
            }
        }
        else {
            up = coins[i][j] + helper(i-1,j,coins,k,dp);
        }
        
        return dp[i][j][k] = max(up,left);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size();
        int m = coins[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,INT_MIN)));
        return helper(n-1,m-1,coins,0,dp);
    }
};
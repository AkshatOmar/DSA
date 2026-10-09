class Solution {
public:
    int helper(vector<int>&prices,int i, bool buy,int n,vector<vector<int>>&dp) {
        if(i>=n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;
        if(buy) {
            int take = -prices[i] + helper(prices,i+1,false,n,dp);
            int notake = helper(prices,i+1,true,n,dp);
            profit = max(take,notake);
        }
        else {
            int take = prices[i] + helper(prices,i+1,true,n,dp);
            int notake = helper(prices,i+1,false,n,dp);
            profit = max(take,notake);
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return helper(prices,0,true,n,dp);
    }
};
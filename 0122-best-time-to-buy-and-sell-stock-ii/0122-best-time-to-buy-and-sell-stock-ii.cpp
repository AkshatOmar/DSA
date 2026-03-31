class Solution {
public:
    int helper(vector<int>&prices, int i, int n, bool buy,vector<vector<int>>&dp) {
        if(i == n) return 0;
        int profit = INT_MIN;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy) {
            profit = max(-prices[i] + helper(prices,i+1,n,false,dp),helper(prices,i+1,n,true,dp));
        }
        else {
            profit = max(prices[i] + helper(prices,i+1,n,true,dp),helper(prices,i+1,n,false,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(prices,0,n,true,dp);
    }
};
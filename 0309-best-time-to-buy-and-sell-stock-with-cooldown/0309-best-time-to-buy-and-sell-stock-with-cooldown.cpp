class Solution {
public: 
    int helper(vector<int>&prices,int n, int i, bool buy, vector<vector<int>>&dp) {
        if(i>=n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit = 0;

        if(buy) {
            profit = max(-prices[i]+helper(prices,n,i+1,false,dp),helper(prices,n,i+1,true,dp));
        }
        else {
            profit = max(prices[i]+helper(prices,n,i+2,true,dp),helper(prices,n,i+1,false,dp));
        }
        return dp[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(prices,n,0,true,dp);
    }
};
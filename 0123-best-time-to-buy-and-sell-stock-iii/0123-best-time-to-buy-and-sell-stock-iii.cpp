class Solution {
public:
    int helper(vector<int>&prices, int i, int n, bool buy, int buyCnt,vector<vector<vector<int>>>&dp) {
        if(i >= n) return 0;
        if(buyCnt >= 2) return 0;
        if(dp[i][buy][buyCnt] != -1) return dp[i][buy][buyCnt];
        int profit = 0;
        if(buy) {
            profit = max(-prices[i] + helper(prices,i+1,n,false,buyCnt,dp),helper(prices,i+1,n,true,buyCnt,dp));
        }
        else {
            profit = max(prices[i] + helper(prices,i+1,n,true,buyCnt+1,dp),helper(prices,i+1,n,false,buyCnt,dp));
        }
        return dp[i][buy][buyCnt] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return helper(prices,0,n,true,0,dp);
    }
};
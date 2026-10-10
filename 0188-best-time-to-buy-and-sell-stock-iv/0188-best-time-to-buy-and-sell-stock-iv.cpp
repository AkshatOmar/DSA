class Solution {
public:
    int n;
    int helper(int k, vector<int>&prices, int i, bool buy,vector<vector<vector<int>>>&dp) {
        if(i >=n) return 0;
        if(k <= 0) return 0;
        int profit = 0;
        if(dp[i][k][buy] != -1) return dp[i][k][buy];
        if(buy) {
            profit = max(-prices[i]+ helper(k,prices,i+1,false,dp), helper(k,prices,i+1,true,dp));
        }
        else {
            profit = max(prices[i] + helper(k-1,prices,i+1,true,dp),helper(k,prices,i+1,false,dp));
        }
        return dp[i][k][buy] = profit;
    }
    int maxProfit(int k, vector<int>& prices) {
         n = prices.size();
         vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return helper(k, prices,0,true,dp);
    }
};
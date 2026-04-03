class Solution {
public:
    int helper(int i, int buy, vector<int>&prices,vector<vector<int>>&dp) {
        if(i == prices.size()) return 0;
        int take = -1e9;
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy == 1) {
            take = max(helper(i+1,1,prices,dp), -prices[i]+helper(i+1,0,prices,dp));
        }
        else{
            take = max(helper(i+1,0,prices,dp), prices[i]+helper(i+1,1,prices,dp));
        }
        return dp[i][buy] = take;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
        dp[n-1][0] = 0;
        dp[n-1][1] = 0;
        for(int i = n-1;i>=0;i--) {
            for(int buy = 0;buy<2;buy++) {
                
                int profit = 0;
                if(buy == 1) {
                    profit = max(dp[i+1][1], -prices[i] + dp[i+1][0]);
                }else {
                    profit = max(dp[i+1][0], prices[i] + dp[i+1][1]);
                }
                dp[i][buy] = profit;
            }
        }
        return dp[0][1];
    }
};
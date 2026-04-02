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
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(0,1,prices,dp);
    }
};
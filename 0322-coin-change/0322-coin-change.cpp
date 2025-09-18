class Solution {
public:
    int helper(vector<int>&coins,int amount,vector<int>&dp) {
        if(amount == 0) {
            return 0;
        }
        if(amount<0) return INT_MAX;
        if(dp[amount] != -1) return dp[amount];
        int ans = INT_MAX;
        for(int coin : coins) {
            int res = helper(coins, amount - coin,dp);
            if(res != INT_MAX) {
                ans = min(ans,1+res);
            }
        }
        return dp[amount] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {    
        vector<int>dp(amount+1,-1);    
        int ans = helper(coins,amount,dp);
        if(ans == INT_MAX){
            return -1;
        }
        else{
            return ans;
        }
    }
};
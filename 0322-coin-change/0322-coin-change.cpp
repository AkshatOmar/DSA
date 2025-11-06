class Solution {
public:
    int helper(vector<int>&coins, int amount,int idx,vector<vector<int>>&dp) {
        if(idx == 0) {
            if(amount%coins[0] == 0) return amount/coins[0];
            else return 1e9;
        }
        if(dp[idx][amount] != -1) return dp[idx][amount];
        int nopick = helper(coins,amount,idx-1,dp);
        int pick = 1e9;
        if(amount >= coins[idx]){
            pick = 1 + helper(coins,amount-coins[idx],idx,dp);
        }
        return dp[idx][amount] = min(pick,nopick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int res = helper(coins,amount,n-1,dp);
        if(res >= 1e9) return -1;
        return res;
    }
};
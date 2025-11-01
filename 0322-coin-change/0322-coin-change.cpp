class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        for(int T =0;T<=amount;T++) {
            if(T%coins[0] == 0) dp[0][T] = T/coins[0];
            else dp[0][T] = 1e9;
        }
        for(int idx = 1;idx<n;idx++) {
            for(int T = 0;T<=amount;T++) {
                int nopick = dp[idx-1][T];
                int pick = 1e9;
                if(coins[idx]<=T) {
                    pick = 1+dp[idx][T - coins[idx]];
                }
                dp[idx][T] = min(pick,nopick);
            }
        }
        int  ans = dp[n-1][amount];
        return (ans>=1e9) ? -1 : ans;
    }
};
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int>dp(amount+1,0);
        dp[0] = 1;
        for(int idx = 0;idx<n;idx++) {
            for(int T = coins[idx];T<=amount;T++) {
                dp[T] += dp[T-coins[idx]];
            }
        }
        return (int)dp[amount];
    }
};
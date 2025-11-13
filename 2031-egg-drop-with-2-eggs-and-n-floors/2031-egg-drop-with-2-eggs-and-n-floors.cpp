class Solution {
public:
    int helper(int e, int f,vector<vector<int>>&dp) {
        if(f == 0 || f == 1) return f;
        if(e == 1) return f;
        if(dp[e][f] != -1) return dp[e][f];
        int mini = 1e9;
        for(int k = 1;k<=f;k++) {
            int temp = 1+max(helper(e-1,k-1,dp),helper(e,f-k,dp));
            mini = min(temp,mini);
        }
        return dp[e][f] = mini;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(3,vector<int>(n+1,-1));
        return helper(2,n,dp);
    }
};
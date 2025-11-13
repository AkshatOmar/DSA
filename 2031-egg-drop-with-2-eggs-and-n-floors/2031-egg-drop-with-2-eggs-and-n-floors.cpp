class Solution {
public:
    
    int twoEggDrop(int n) {
        vector<vector<int>>dp(3,vector<int>(n+1,0));
        
        for(int f = 1;f<=n;f++) {
            dp[1][f] = f;
        }
        for(int e = 2;e<=2;e++) {
            dp[e][0] = 0;
            dp[e][1] = 1;
            for(int f = 2;f<=n;f++) {
                int mini = 1e9;
                for(int k = 1;k<=f;k++) {
                    int maxAttempts = 1+ max(dp[e-1][k-1],dp[e][f-k]);
                    mini = min(maxAttempts,mini);
                }
                dp[e][f] = mini;
            }
        }
        return dp[2][n];
    }
};
class Solution {
public:
    int helper(int eggs, int floor,vector<vector<int>>&dp) {
        if(floor == 0 || floor == 1) return floor;
        if(eggs == 1) return floor;
        if(dp[eggs][floor] != -1) return dp[eggs][floor];
        int mini = 1e9;
        for(int k = 1;k<=floor;k++) {
            int temp = 1+ max(helper(eggs-1,k-1,dp),helper(eggs,floor-k,dp));
            mini = min(temp,mini);
        }
        return dp[eggs][floor] = mini;
    }
    int twoEggDrop(int n) {
        vector<vector<int>>dp(3,vector<int>(n+1,-1));
        return helper(2,n,dp);
    }
};
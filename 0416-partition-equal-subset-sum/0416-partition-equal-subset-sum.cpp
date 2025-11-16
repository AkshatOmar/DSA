class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for(int i = 0;i<n;i++) totSum += nums[i];
        if(totSum%2 != 0) return false;
        vector<vector<bool>>dp(n,vector<bool>(totSum/2+1,false));
        for(int i = 0;i<n;i++){
            dp[i][0] = true;
        }
        //if(nums[0]<=totSum/2) dp[0][nums[0]] = false;
        for(int i = 1;i<n;i++) {
            for(int j = 1;j<=totSum/2;j++) {
                bool nopick = dp[i-1][j];
                bool pick = false;
                if(j>=nums[i]) pick = dp[i-1][j-nums[i]];
                dp[i][j] = pick|nopick;
            }
        }
        return dp[n-1][totSum/2];
    }
};
class Solution {
public:
    bool helper(vector<int>&nums, int i, int tgt,vector<vector<int>>&dp) {
        if(i == 0) {
            if(nums[0] == tgt) return true;
            else return false;
        }
        if(dp[i][tgt]!=-1)return dp[i][tgt];
        int nopick = helper(nums,i-1,tgt,dp);
        int pick = false;
        if(tgt>=nums[i]) {
            pick = helper(nums,i-1,tgt-nums[i],dp);
        }
        return dp[i][tgt] = pick|nopick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int totSum = 0;
        for(int i = 0;i<n;i++) totSum += nums[i];
        if(totSum%2 != 0) return false;
        vector<vector<int>>dp(n,vector<int>(totSum/2+1,-1));
        return helper(nums,n-1,totSum/2,dp);
    }
};
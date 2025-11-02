class Solution {
public:
    int helper(vector<int>&nums,int target,int idx,vector<vector<int>>&dp) {
        if(idx == 0) {
            if(target == 0 && nums[0] == 0) return 2;
            if(target == 0 ||nums[0] == target) return 1;
            return 0;
        }
        if(dp[idx][target] != -1) return dp[idx][target];
        int nonpick = helper(nums,target,idx-1,dp);
        int pick = 0;
        if(nums[idx]<=target) {
            pick = helper(nums,target-nums[idx],idx-1,dp);
        }
        return dp[idx][target] = pick + nonpick;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int i = 0;i<n;i++) {
            totSum+=nums[i];
        }
        if((totSum+target)%2 != 0 || abs(target)>totSum)return 0;
        int T = (totSum+target)/2;
        vector<vector<int>>dp(n,vector<int>(T+1,-1));
        return helper(nums, T, n-1,dp);
    }
};
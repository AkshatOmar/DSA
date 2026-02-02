class Solution {
public:
    bool helper(vector<int>&nums,int target, int i,vector<vector<int>>&dp) {
        if(i<0) {
            if(target == 0) return true;
            else return false;
        }
        if(dp[i][target] != -1) return dp[i][target];
        bool skip = helper(nums,target,i-1,dp);
        bool take = false;
        if(target>=nums[i]) {
            take = helper(nums,target-nums[i],i-1,dp);
        }
        return dp[i][target] = skip|take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int  i = 0;i<n;i++) {
            sum+=nums[i];
        }
        if(sum%2 != 0) {
            return false;
        }
        vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
        return helper(nums,sum/2,n-1,dp);
    }
};
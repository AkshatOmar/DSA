class Solution {
public:
    bool helper(vector<int>&nums, int target,int idx,vector<vector<int>>&dp){
        if(target == 0) return true;
        if(idx == 0) return (nums[idx] == target);
        if(dp[idx][target]!=-1) return dp[idx][target];
        bool nopick = helper(nums,target,idx-1,dp);
        bool pick = false;
        if(target>=nums[idx]) {
            pick = helper(nums,target-nums[idx],idx-1,dp);
        }
        return dp[idx][target] = pick||nopick;
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i =0;i<n;i++){
            sum +=nums[i];
        }
        if(sum %2 == 0) {
            vector<vector<int>>dp(n,vector<int>(sum/2+1,-1));
            return helper(nums,sum/2,n-1,dp);
        }
        else return false;
    }
};
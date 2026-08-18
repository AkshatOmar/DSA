class Solution {
public:
    int helper(vector<int>&nums,int i, int n,vector<int>&dp) {
        if(i > n-1) {
            return 0;
        }
        if(dp[i] != -1) return dp[i];
        int pick = nums[i] + helper(nums,i+2,n,dp);
        int nopick = helper(nums,i+1,n,dp);
        return dp[i] = max(pick,nopick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(nums,0,n,dp);
    }
};
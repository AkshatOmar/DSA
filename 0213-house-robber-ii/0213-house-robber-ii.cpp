class Solution {
public:
    
    int helper(vector<int>&nums, int n, int i,vector<int>&dp) {
        if(i > n-1) return 0;
        if(dp[i]!=-1)return dp[i];
        int pick = nums[i] + helper(nums,n,i+2,dp);
        int nopick = helper(nums,n,i+1,dp);
        return dp[i] = max(pick,nopick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int>dp1(n,-1);
        vector<int>dp2(n,-1);
        return max(helper(nums,n,1,dp1),helper(nums,n-1,0,dp2));
    }
};
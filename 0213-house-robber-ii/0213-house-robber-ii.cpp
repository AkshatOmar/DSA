class Solution {
public:
    int helper(int i, vector<int>&nums,vector<int>&dp) {
        if(i == 0) {
            return nums[0];
        }
        if(i<0) return 0;
        if(dp[i]!=-1) return dp[i];
        int nopick = helper(i-1,nums,dp);
        int pick = nums[i] + helper(i-2,nums,dp);
        return dp[i] = max(pick,nopick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<int>dp1(n,-1);
        int case1 = helper(n-2,nums,dp1);
        vector<int>dp2(n,-1);
        vector<int> temp(nums.begin() + 1, nums.end());
        int case2 = helper(n-2,temp,dp2);
        return max(case2,case1);
    }
};
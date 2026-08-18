class Solution {
public:
    
    int helper(vector<int>&nums, int n, int i, bool flag,vector<vector<int>>&dp) {
        if(i > n-1) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        if(i == n-1) {
            if(flag) {
                return nums[i];
            } else return 0;
        }
        bool nextFlag = (i== 0) ? false : flag; 
        int pick = nums[i] + helper(nums,n,i+2,nextFlag,dp);
        int nopick = helper(nums,n,i+1,flag,dp);
        return dp[i][flag] = max(pick,nopick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return helper(nums,n,0, true,dp);
    }
};
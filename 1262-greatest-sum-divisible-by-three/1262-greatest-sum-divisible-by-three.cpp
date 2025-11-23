class Solution {
public:
    int helper(vector<int>&nums, int i,int mod,vector<vector<int>>&dp) {
        if(i < 0) {
            if(mod%3 == 0) return 0;
            else return -1e9;
        }
        if(dp[i][mod] != -1) return dp[i][mod];
        int take = nums[i] + helper(nums,i-1,(mod+nums[i])%3,dp);
        int notake = helper(nums,i-1,mod,dp);
        return dp[i][mod] = max(take,notake);
    }
    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp(n,vector<int>(3,-1));
        int ans =  helper(nums,n-1,0,dp);
        return max(ans,0);
        
    }
};
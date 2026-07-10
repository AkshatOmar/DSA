class Solution {
public:
    bool helper(vector<int>&nums,int i, int n,vector<int>&dp) {
        
        if(i == n-1) return true;
        if(i>=n || nums[i] == 0) return false;
        if(dp[i] != -1) return dp[i];

        for(int j = 1;j<=nums[i] && i+j < n;j++) {
            if(helper(nums,i+j,n,dp)) return dp[i+j] = true;
        }
        return dp[i] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(nums,0,n,dp);
    }
};
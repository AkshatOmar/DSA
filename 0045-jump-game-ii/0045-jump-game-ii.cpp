class Solution {
public:
    int helper(int i, int n, vector<int>&nums,vector<int>&dp) {
        if(i == n-1) return 0;
        
        int ans = 1e9;
        if(dp[i] != -1) return dp[i];
        for(int j = 1;j<=nums[i] && j+i <n;j++) {
            ans = min(ans, 1+ helper(j+i,n,nums,dp));
        }
        return dp[i] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return helper(0,n,nums,dp);
    }
};
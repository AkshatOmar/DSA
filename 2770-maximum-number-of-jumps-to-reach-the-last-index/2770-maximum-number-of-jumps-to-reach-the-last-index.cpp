class Solution {
public:
    int n;
    int helper(vector<int>&nums, int target, int i,vector<int>&dp) {
        if(i == n-1) {
            return 0;
        }
        if(dp[i] != -2) return dp[i];
        int ans = -1;
        for(int j = i+1;j<n;j++) {
            if(abs(nums[j]-nums[i]) <= target) {
                int temp = helper(nums,target,j,dp);

                if(temp != -1) ans = max(ans,1+temp);
            }
            
        }
        return dp[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        vector<int>dp(n,-2);
        return helper(nums, target,0,dp);

    }
};
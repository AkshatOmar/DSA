class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        vector<int>dp(n,0);
        dp[0] = nums[0];
        for(int i = 1;i<n;i++) {
            int nopick = dp[i-1];
            int pick = nums[i];
            if(i>1)pick += dp[i-2];
            dp[i] = max(pick, nopick);
        }
        return dp[n-1];
    }
};
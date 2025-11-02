class Solution {
public:
  
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totSum = 0;
        for(int i = 0;i<n;i++) {
            totSum+=nums[i];
        }
        if((totSum+target)%2 != 0 || abs(target)>totSum)return 0;
        int T = (totSum+target)/2;
        vector<vector<int>>dp(n,vector<int>(T+1,0));
        if(nums[0] == 0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(nums[0]!=0 && nums[0] <=T) dp[0][nums[0]] = 1;
        for(int i = 1;i<n;i++) {
            for(int sum = 0;sum<=T;sum++) {
                int nonpick = dp[i-1][sum];
                int pick = 0;
                if(nums[i]<=sum) pick = dp[i-1][sum-nums[i]];
                dp[i][sum] = pick+nonpick;
            }
        }
        return dp[n-1][T];
    }
};
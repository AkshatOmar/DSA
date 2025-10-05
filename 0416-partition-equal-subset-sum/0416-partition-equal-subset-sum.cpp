class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum =0;
        for(int i =0;i<n;i++){
            sum +=nums[i];
        }
        if(sum %2 == 0) {
            vector<vector<bool>>dp(n,vector<bool>(sum/2+1,0));
            for(int i=0;i<n;i++) {
                dp[i][0] = true;
            }
            if(nums[0]<=sum/2)dp[0][nums[0]] = false;
            for(int i = 1;i<n;i++) {
                for(int target = 1;target<=sum/2;target++) {
                    bool nopick = dp[i-1][target];
                    bool pick = false;
                    if(target>=nums[i]) {
                        pick = dp[i-1][target-nums[i]];
                    }
                    dp[i][target]=pick|nopick;
                }
            }
            return dp[n-1][sum/2];
        }
        else return false;
    }
};
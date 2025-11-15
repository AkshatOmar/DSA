class Solution {
public:
    int ways = 0;
    void helper(vector<int>&nums,int idx, int currSum, int target) {
        if (idx == nums.size()) {
                if( currSum == target) ways++;
        }
        else {
            helper(nums,idx+1, currSum+nums[idx],target);
            helper(nums,idx+1,currSum-nums[idx],target);
        }
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        helper(nums,0,0,target);
        return ways;
    }
};
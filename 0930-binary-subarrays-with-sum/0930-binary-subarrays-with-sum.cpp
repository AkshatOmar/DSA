class Solution {
public:
    int helper(vector<int>&nums,int goal) {
        if(goal < 0) {
            return 0;
        }
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int subarray = 0;
        while(j<n) {
            if(nums[j] == 1) {
                sum++;
            }
            while(sum > goal) {
                if(nums[i] == 1) {
                    sum--;
                }
                i++;
            }
            subarray += (j-i+1);
            j++;
        }
        return subarray;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return helper(nums,goal) - helper(nums,goal-1);
    }
};
class Solution {
public:
    int subarray(vector<int>&nums,int goal) {
        if(goal < 0) return 0;
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int cnt = 0;
        while(j<n) {
            if(nums[j] == 1) {
                sum++;
            }
            while(sum > goal) {
                if(nums[i] == 1) sum--;
                i++;
            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarray(nums,goal) - subarray(nums,goal-1);
    }
};
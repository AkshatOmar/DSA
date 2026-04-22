class Solution {
public:
    int func(vector<int>&nums, int goal) {
        int n = nums.size();
        if(goal < 0) return 0;
        int i = 0, j = 0;
        long long pref = 0;
        int cnt = 0;
        while(j<n) {
            pref += nums[j];
            while(pref > goal) {
                pref -= nums[i];
                i++;

            }
            cnt += (j-i+1);
            j++;
        }
        return cnt;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return func(nums,goal) - func(nums,goal - 1);
    }
};
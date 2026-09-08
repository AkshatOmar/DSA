class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0;
        for(int i = 0;i<n;i++) {
            int maxi = INT_MIN;
            int mini = INT_MAX;
            for(int j = i;j<n;j++) {
                maxi = max(nums[j],maxi);
                mini = min(nums[j],mini);
                sum += (maxi-mini);
            }
        }
        return sum;
    }
};
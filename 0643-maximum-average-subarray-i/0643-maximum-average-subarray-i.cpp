class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0;i<k;i++) {
            sum += nums[i];
        }   
            int left = 0;
            int maxSum = sum;
        for(int right = k;right<n;right++) {
            sum += nums[right] - nums[left];
            left++;
            maxSum = max(maxSum, sum);
        }    
        return (double)maxSum/k;
    }
};
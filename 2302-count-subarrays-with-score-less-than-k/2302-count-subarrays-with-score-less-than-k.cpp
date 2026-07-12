class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        int i = 0,j = 0;
        long long currSum = 0;
        long long ans = 0;
        while(j<n) {
            currSum += nums[j];
            while(i<= j && currSum*(j-i+1) >= k) {
                currSum -= nums[i];
                i++;
            }
            ans += j-i+1;
            j++;

        }
        return ans;
    }
};
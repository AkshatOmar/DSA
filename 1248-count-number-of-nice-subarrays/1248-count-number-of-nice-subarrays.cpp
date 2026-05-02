class Solution {
public:
    int subarray(vector<int>&nums, int k) {
        if( k<0) return 0;
        int n = nums.size();
        int i = 0, j = 0;
        int odds = 0;
        int cnt = 0;
        while(j<n) {
            if(nums[j] %2 == 1) odds++;
            while(odds > k) {
                if(nums[i] % 2 == 1) odds--;
                i++;
            }
            cnt += j-i+1;
            j++;
        }
        return cnt;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return subarray(nums,k) - subarray(nums,k-1);
    }
};
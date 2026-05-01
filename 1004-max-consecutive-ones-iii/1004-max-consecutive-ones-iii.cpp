class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        int i = 0;
        int j = 0;
        int maxlen = INT_MIN;
        int kcnt = 0;
        while(j<n) {
            if(nums[j] == 0) {
                kcnt++;
            }
            while(kcnt>k) {
                if(nums[i] == 0) kcnt--;
                i++;
            }
            maxlen = max(maxlen,j-i+1);
            j++;
            
        }
        return maxlen;
    }
};
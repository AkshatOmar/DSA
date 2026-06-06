class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,0);
        int pref = 0;
        for(int i = 0;i<n;i++) {
            ans[i] = pref;
            pref += nums[i];
        }
        int suff = 0;
        for(int i = n-1;i>=0;i--) {
            ans[i] = abs(ans[i] - suff);
            suff += nums[i];
        }
        return ans;
    }
};
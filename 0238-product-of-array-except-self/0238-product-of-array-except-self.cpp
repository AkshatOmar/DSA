class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        vector<int>pref(n,1);
        vector<int>suff(n,1);
        for(int i = 1;i<n;i++) {
            pref[i] = nums[i-1]*pref[i-1];
            
        }
        for(int i = n-2;i>=0;i--) {
            suff[i] = nums[i+1]*suff[i+1];
        }
        for(int i = 0;i<n;i++) {
            ans[i] = pref[i]*suff[i];
        }
        return ans;
    }
};
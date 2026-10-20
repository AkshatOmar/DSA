class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        
        vector<int>suff(n,1);
        for(int i = 1;i<n;i++) {
            suff[n-i-1] = nums[n-i]*suff[n-i];
        }
        int pref = 1;
        ans[0] = suff[0];
        for(int i = 1;i<n;i++) {
            pref = nums[i-1]*pref;
            ans[i] = pref*suff[i];
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans;
        int n = nums.size();
        vector<int>pref(n,1);
        vector<int>suff(n,1);

        for(int i = 1;i<n;i++) {
            pref[i] = pref[i-1] * nums[i-1];
            suff[n-i-1] = suff[n-i] * nums[n-i]; 
        }
        // for(int i = n-2;i>=0;i--) {
        //     suff[i] = suff[i+1]* nums[i+1];
        // }
        for(int i = 0;i<n;i++) {
            ans.push_back(pref[i]*suff[i]);
        }
        return ans;
    }
};
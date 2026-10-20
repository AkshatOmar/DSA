class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n,1);
        
        
        for(int i = 1;i<n;i++) {
            ans[n-i-1] = nums[n-i]*ans[n-i];
        }
        int pref = 1;
        
        for(int i = 1;i<n;i++) {
            pref = nums[i-1]*pref;
            ans[i] = pref*ans[i];
        }
        return ans;
    }
};
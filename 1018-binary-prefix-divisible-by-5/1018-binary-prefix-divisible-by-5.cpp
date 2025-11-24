class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool>ans;
        int n = nums.size();
        int rem = 0;
        for(int i = 0;i<n;i++) {
            rem = ((rem<<1) + nums[i])%5;
            if(rem == 0) {
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
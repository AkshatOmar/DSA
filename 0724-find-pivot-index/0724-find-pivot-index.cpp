class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        
        vector<int>suff(n);

        for(int i = 1;i<n;i++) {
            suff[n-i-1] = suff[n-i]+nums[n-i];
        }
        int pref = 0;
        for(int i = 0;i<n;i++) {
            if(pref == suff[i]) {
                return i;
            }
            pref+=nums[i];
        }
        return -1;
    }
};
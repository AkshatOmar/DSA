class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();

        vector<int>pref(n);
        vector<int>suff(n);

        for(int i = 1;i<n;i++) {
            pref[i] = pref[i-1]+nums[i-1];
            suff[n-i-1] = suff[n-i]+nums[n-i];
        }
        for(int i = 0;i<n;i++) {
            if(pref[i] == suff[i]) {
                return i;
            }
        }
        return -1;
    }
};
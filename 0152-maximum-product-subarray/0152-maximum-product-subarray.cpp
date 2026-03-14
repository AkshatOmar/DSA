class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int pref = 1;
        int suff = 1;
        int maxPref = INT_MIN;
        int maxSuff = INT_MIN;
        for(int i = 0;i<n;i++) {
            pref = pref*nums[i];
            suff  = suff* nums[n-1-i];
            maxPref = max(maxPref,pref);
            maxSuff = max(maxSuff,suff);
            if(pref == 0){
                pref = 1;
            }
            if(suff == 0) {
                suff = 1;
            }
        }
        return max(maxPref,maxSuff);
    }
};
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int suff = 0;
        for(int i = 0;i<n;i++) {
            suff += nums[i];
        }
        int pref = 0;
        for(int i = 0;i<n;i++) {
            int num = suff-nums[i]-pref;
            if(num == pref) {
                return i;
            }
            pref+=nums[i];
        }
        return -1;
    }
};
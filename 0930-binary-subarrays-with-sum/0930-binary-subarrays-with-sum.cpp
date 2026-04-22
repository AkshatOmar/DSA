class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int cnt = 0;
        unordered_map<int,int>mp;
        mp[0] = 1;
        int pref = 0;
        for(int i = 0;i<n;i++) {
            pref += nums[i];
            cnt += mp[pref-goal];
            mp[pref]++;
        }
        return cnt;
    }
};
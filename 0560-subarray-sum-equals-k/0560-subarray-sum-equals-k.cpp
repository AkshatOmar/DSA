class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int pref = 0;
        unordered_map<int,int>mp;
        mp[0]=1;
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            pref += nums[i];
            cnt += mp[pref-k];
            mp[pref]++;
        }
        return cnt;
    }
};
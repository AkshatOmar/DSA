class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>pre(n+1,0);
        for(int i = 1;i<=n;i++) {
            pre[i] = nums[i-1] + pre[i-1];
        }
        long long ans = LLONG_MIN;
        vector<long long>minPref(k,LLONG_MAX);
        for(int i = 0;i<=n;i++) {
            int mod = i%k;
            if(minPref[mod] != LLONG_MAX) {
                ans = max(ans, pre[i]-minPref[mod]);
            }
            minPref[mod] = min(minPref[mod],pre[i]);
        }
        return ans == LLONG_MIN ? 0 : ans;
    }
};
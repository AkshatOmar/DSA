class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int mod = 1e9 + 7;
        int n = nums.size();
        vector<long long>arr(n);
        for(int i = 0;i<n;i++) {
            arr[i] = nums[i];
        }
        for(auto it : queries) {
            int l = it[0];
            int r = it[1];
            int k = it[2];
            int v = it[3];
            for(int i = l;i<=r;i+=k) {
                arr[i] = (arr[i]*v) % mod;
                
            }
        }
        int ans = 0;
        for(int i = 0;i<nums.size();i++) {
            ans ^= arr[i];
        }
        return ans;
    }
};
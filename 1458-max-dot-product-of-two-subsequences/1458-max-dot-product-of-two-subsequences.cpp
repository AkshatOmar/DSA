class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int i = 0;i<=n;i++) {
            dp[i][0] = -1e8;
        }
        for(int j = 0;j<=m;j++) {
            dp[0][j] = -1e8;
        }
        for(int i = 1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                int nopick1 = dp[i-1][j];
                int nopick2 = dp[i][j-1];
                int pick = max(nums1[i-1]*nums2[j-1],nums1[i-1]*nums2[j-1]+dp[i-1][j-1]);
                dp[i][j] = max({pick,nopick1,nopick2});
            }
        }
        return dp[n][m];
    }
};
class Solution {
public:
    
    int helper(vector<int>&nums1,vector<int>&nums2,int i, int j,vector<vector<int>>&dp) {
        if(i < 0 || j < 0) {
            return -1e9;
        }
    if(dp[i][j] != -1) return dp[i][j];
        int nopick1 = helper(nums1,nums2,i-1,j,dp);
        int nopick2 = helper(nums1,nums2,i,j-1,dp);
        int pick = max(nums1[i]*nums2[j],nums1[i]*nums2[j]+helper(nums1,nums2,i-1,j-1,dp));
        return dp[i][j] = max({pick,nopick1,nopick2});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(nums1,nums2,n-1,m-1,dp);
    }
};
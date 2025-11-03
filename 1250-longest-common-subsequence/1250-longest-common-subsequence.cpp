class Solution {
public:
    int helper(string &t1, string& t2,int i1,int i2,vector<vector<int>>&dp) {
        if(i1<0|| i2<0) {
            return 0;
        }
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(t1[i1] == t2[i2]) {
            return dp[i1][i2] = 1 + helper(t1,t2,i1-1,i2-1,dp);
        }
        int left = helper(t1,t2,i1-1,i2,dp);
        int right = helper(t1,t2,i1,i2-1,dp);
        return dp[i1][i2] = max(left,right);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1));
        return helper(text1,text2,n1-1,n2-1,dp);
    }
};
class Solution {
public:
    int helper(string &s1, string &s2, int i, int j,vector<vector<int>>&dp) {
        if(i<0) {
            int remain = 0;
            for(int j1 = j;j1>=0;j1--) {
                remain+=s2[j1];
            }
            return remain;
        }
        if(j<0) {
            int remain = 0;
            for(int i1 = i;i1>=0;i1--) {
                remain+=s1[i1];
            }
            return remain;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int same = 1e9;
        int delete1 = 1e9;
        int delete2 = 1e9;
        if(s1[i] == s2[j]) {
            same = helper(s1,s2,i-1,j-1,dp);
        }
        else{
            delete1 = s1[i]+helper(s1,s2,i-1,j,dp);
            delete2 = s2[j]+helper(s1,s2,i,j-1,dp);
        }
        return dp[i][j] = min({same,delete1,delete2});
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(s1,s2,n-1,m-1,dp);
    }
};
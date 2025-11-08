class Solution {
public:
    bool helper(string &s, string &p, int i, int j,vector<vector<int>>&dp) {
        if(i<0 && j<0) {
            return true;
        }
        if(j<0 && i>=0) {
            return false;
        }
        if(i<0 && j>=0) {
            for(int c = 0;c<=j;c++) {
                if(p[c] != '*') return false;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];
        bool x = false;
        if(s[i] == p[j] || p[j] == '?') {
            x = helper(s,p,i-1,j-1,dp);
        }
        else if(p[j] == '*') {
            x = helper(s,p,i-1,j,dp)|helper(s,p,i,j-1,dp);
        }
        return dp[i][j] = x;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(s,p,n-1,m-1,dp);
    }
};
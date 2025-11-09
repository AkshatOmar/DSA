class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0] = true;
        //i>=0 && j<0
        for(int i = 1;i<=n;i++) {
            dp[i][0] = false;
        }
        //i<0 && j>=0
        for(int j = 1;j<=m;j++) {
            bool flag = true;
            for(int j1 = 1;j1<=j;j1++) {
                if(p[j1-1]!='*') {
                    flag =false;
                    break;
                }
            }
            dp[0][j] =flag;
        }
        //dp table
        for(int i =1;i<=n;i++) {
            for(int j = 1;j<=m;j++) {
                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                if(p[j-1] == '*') {
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};
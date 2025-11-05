class Solution {
public:
    
    int helper(string &s1,string &s2, int i,int j,vector<vector<int>>&dp) {
        if(i<0 || j<0) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        if(s1[i] == s2[j]) return dp[i][j] = 1+helper(s1,s2,i-1,j-1,dp);
        else{
            return dp[i][j] = max(helper(s1,s2,i-1,j,dp),helper(s1,s2,i,j-1,dp));
        }
    }
        
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        string s2 = s;
        reverse(s2.begin(),s2.end());
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(s,s2,n-1,n-1,dp);

    }
};
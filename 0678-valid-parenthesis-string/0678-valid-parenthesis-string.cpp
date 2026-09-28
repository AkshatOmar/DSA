class Solution {
public:
    bool helper(string s, int n, int idx, int cnt,vector<vector<int>>&dp) {
        if(cnt < 0) return false;
        if(idx >= n && cnt == 0) return true;
        if(idx >= n && cnt != 0) return false;
        if(dp[idx][cnt] != -1) return dp[idx][cnt];
        if(s[idx] == '*') {
            return dp[idx][cnt] = helper(s,n,idx+1,cnt+1,dp) || helper(s,n,idx+1,cnt-1,dp) || helper(s,n,idx+1,cnt,dp);
            
        }
        if(s[idx] == '(')
            return dp[idx][cnt] = helper(s,n,idx+1,cnt+1,dp);
        return dp[idx][cnt] = helper(s,n,idx+1,cnt-1,dp);
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(s,n,0,0,dp);
    }
};
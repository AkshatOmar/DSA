class Solution {
public:
    bool helper(string s, int n, int i,int cnt,vector<vector<int>>&dp) {
        if(cnt<0) return false;
        if(i == n) {
            if(cnt == 0)
                return true;
            else return false;
        }
        if(dp[i][cnt] != -1) return dp[i][cnt];
        
        
        if(s[i] == '(') {
            return dp[i][cnt] = helper(s,n,i+1,cnt+1,dp);
        }
        else if(s[i] == ')') {
            return dp[i][cnt] = helper(s,n,i+1,cnt-1,dp);
        }
        return dp[i][cnt] = helper(s,n,i+1,cnt+1,dp) || helper(s,n,i+1,cnt,dp) || helper(s,n,i+1,cnt-1,dp);
        
    }
    bool checkValidString(string s) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return helper(s, n, 0,0,dp);
    }
};
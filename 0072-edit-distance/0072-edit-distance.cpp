class Solution {
public:
    int helper(string &w1,string &w2, int i, int j,vector<vector<int>>&dp) {
        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(w1[i] == w2[j]) {
            return dp[i][j] = helper(w1,w2,i-1,j-1,dp);
        }

        else {
            //insert -> i,j-1
            //delete -> i-1,j
            //replace -> i-1,j-1
            return dp[i][j] = min({1+helper(w1,w2,i,j-1,dp),1+helper(w1,w2,i-1,j,dp),1+helper(w1,w2,i-1,j-1,dp)});
            
        }
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(),m = word2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return helper(word1,word2,n-1,m-1,dp);
    }
};
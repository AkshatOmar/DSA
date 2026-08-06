class Solution {
public:
    int helper(vector<int>&piles, int n, int i, int j,vector<vector<int>>&dp) {
        if(i>j) {
            return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        int take_i = piles[i] + min(helper(piles,n,i+2,j,dp),helper(piles,n,i+1,j-1,dp));
        int take_j = piles[j] + min(helper(piles,n,i+1,j-1,dp),helper(piles,n,i,j-2,dp));
        return dp[i][j] = max(take_i,take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int sum = 0;
        vector<vector<int>>dp(n,vector<int>(n,-1));
        for(int i = 0;i<n;i++) {
            sum += piles[i];
        }
        int alice =  helper(piles, n, 0,n-1,dp);
        return (alice > sum/2);
    }
};
class Solution {
public:
    int n;
    int m;
    int helper(int i, int j, vector<vector<int>>& dungeon,vector<vector<int>>&dp) {
        
        if(i == n-1 && j == m-1) {
            if(dungeon[i][j] <= 0) {
                return abs(dungeon[i][j]) + 1;
            }
            return 1;
        }

        if(i>=n || j>=m) return 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        int right =  helper(i,j+1,dungeon,dp);
        int down =  helper(i+1,j,dungeon,dp);
        
        int result = min(right,down) - dungeon[i][j];
 
        return dp[i][j] = result > 0 ? result : 1;

    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {

        n = dungeon.size();
        m = dungeon[0].size();

        vector<vector<int>>dp(n,vector<int>(m,-1));

        return helper(0,0,dungeon,dp);
        
    }
    
};
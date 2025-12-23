class Solution {
public:

    int helper(vector<vector<int>>& grid, int i1, int j1, int j2, int n, int m,vector<vector<vector<int>>>&dp) {
        if(j1<0 || j1>m-1 || j2<0 || j2>m-1) return -1e9;
        if(i1 == n-1) {
            if(j1 == j2) {
                return grid[i1][j1];
            }
            return grid[i1][j1]+grid[i1][j2];
        }
        if(dp[i1][j1][j2]!=-1) return dp[i1][j1][j2];
        int maxi = -1e9;
        for(int d1 = -1;d1<=1;d1++) {
            for(int d2 = -1;d2<=1;d2++) {
                if(j1 == j2) {
                    maxi = max(maxi,grid[i1][j1]+helper(grid, i1+1,j1+d1,j2+d2,n,m,dp));
                }
                else{
                    maxi = max(maxi,grid[i1][j1]+grid[i1][j2]+helper(grid,i1+1,j1+d1,j2+d2,n,m,dp));
                }
            }
        }
        return dp[i1][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        return helper(grid,0,0,m-1,n,m,dp);
    }
};
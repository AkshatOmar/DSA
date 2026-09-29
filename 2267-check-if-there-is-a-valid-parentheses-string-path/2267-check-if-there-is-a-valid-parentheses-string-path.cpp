class Solution {
public:
    
    bool helper(vector<vector<char>>&grid, int i, int j, int n, int m, int cnt,vector<vector<vector<int>>>&dp) {
        if(i>=n || j>=m || i<0 || j<0) return false;

        if(grid[i][j] == '(') {
            cnt++;
        }
        else if(grid[i][j] == ')') {
            cnt--;
        }
        if(i == n-1 && j == m-1 && cnt==0) {
            return true;
        }
        if(cnt<0) return false;
        if(dp[i][j][cnt] != -1) return dp[i][j][cnt];
        return dp[i][j][cnt] = helper(grid,i+1,j,n,m,cnt,dp) || helper(grid,i,j+1,n,m,cnt,dp);
        
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(n+m,-1)));
        return helper(grid,0,0,n,m,cnt,dp);

    }
};
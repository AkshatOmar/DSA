class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i = 0;i<n;i++) {
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1;i<n;i++) {
            for(int j = 0;j<n;j++) {
                int diaL = 1e9, up = 1e9, diaR = 1e9;
                if(j-1>=0)diaL = matrix[i][j] + dp[i-1][j-1];
                up = matrix[i][j] + dp[i-1][j];
                if(j+1<n)diaR = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min({diaL, up, diaR});
            }
        }
        int ans = dp[n-1][0];
        for(int i = 0;i<n;i++) {
            ans = min(ans,dp[n-1][i]);
        }
        return ans;

    }
};
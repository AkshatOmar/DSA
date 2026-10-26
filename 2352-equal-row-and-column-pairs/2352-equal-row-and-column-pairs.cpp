class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>transpose(n,vector<int>(m));
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                transpose[i][j] = grid[j][i];
            }
        }
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i] == transpose[j]){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
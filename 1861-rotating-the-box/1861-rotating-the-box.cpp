class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>>res(n,vector<char>(m));
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                res[i][j] = boxGrid[j][i];
            }
            
            
        }
        for(int i = 0;i<n;i++) {
            reverse(res[i].begin(),res[i].end());
        }
        for (int j = 0; j < m; j++) {
            int lowestRowWithEmptyCell = n - 1;
            for (int i = n - 1; i >= 0; i--) {
                if (res[i][j] == '#') {
                    res[i][j] = '.';
                    res[lowestRowWithEmptyCell][j] = '#';
                    lowestRowWithEmptyCell--;
                }
                if (res[i][j] == '*') {
                    lowestRowWithEmptyCell = i - 1;
                }
            }
        }
        return res;
    }
};
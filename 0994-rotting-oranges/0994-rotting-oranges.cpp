class Solution {
public:
    vector<vector<int>>direction{{-1,0},{1,0},{0,-1},{0,1}};
    bool isSafe(int i, int j,int n,int m, vector<vector<int>>&grid) {
        return (i>=0 && i<n && j>=0 && j<m && grid[i][j] == 1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int freshcnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 1) {
                    freshcnt++;
                }else if(grid[i][j] == 2) {
                    q.push({i,j});
                }
            }
        }
        if(freshcnt == 0) return 0;
        int minute = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int r = 0;r<size;r++) {
                auto it = q.front();
                q.pop();
                int i = it.first;
                int j = it.second;
                for(auto &dir : direction) {
                    int new_i = i+dir[0];
                    int new_j = j+dir[1];
                    if(isSafe(new_i,new_j,n,m,grid)) {
                        grid[new_i][new_j] = 2;
                        q.push({new_i,new_j});
                        freshcnt--;
                    }
                }
            }
            minute++;
        }
        return freshcnt == 0 ? minute-1 : -1;
    }
};
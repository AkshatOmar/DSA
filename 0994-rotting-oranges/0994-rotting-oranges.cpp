class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n  = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        int minutes = 0;
        int fresh = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        if(fresh == 0) return 0;
        vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
        while(!q.empty()) {
            int size = q.size();
            for(int k = 0;k<size;k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto &dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    if(new_i >= 0 && new_i <n && new_j>=0 && new_j<m && grid[new_i][new_j] == 1) {
                        grid[new_i][new_j] = 2;
                        q.push({new_i,new_j});
                        fresh--;
                    }
                }
            }
            
            minutes++;
        }
        
        return fresh == 0 ? minutes-1 : -1;
    }
};
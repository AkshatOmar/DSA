class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        //queue to perform bfs
        queue<pair<int,int>>q;
        int cnt = 0;
        int freshOrg = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }
                else if(grid[i][j] == 1) {
                    freshOrg++;
                }
            }
        }
        if(freshOrg == 0) return 0;
        //Multisrc bfs
        while(!q.empty()) {
            int size = q.size();
            for(int k = 0;k<size;k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                for(auto &dir : directions) {
                    int new_i = dir[0] + i;
                    int new_j = dir[1] + j;
                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m) {
                        if(grid[new_i][new_j] == 1) {
                            grid[new_i][new_j] = 2;
                            q.push({new_i,new_j});
                        }

                    }
                }
            }
            cnt++;
        }
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return cnt-1; //-1 coz the last interation of while loop will increase the count without rotting orange
        
    }
};
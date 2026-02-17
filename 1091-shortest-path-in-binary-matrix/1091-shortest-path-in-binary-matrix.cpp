class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] != 0) {
            return -1;
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        int lvl = 0;
        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0;i<sz;i++) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == n-1 && y == m-1) {
                    return lvl+1;
                }
                for(auto &dir : directions) {
                    int new_x = x+dir[0];
                    int new_y = y+dir[1];
                    
                    if(new_x >= 0 && new_x<n && new_y >= 0 && new_y<n && grid[new_x][new_y]==0) {
                        q.push({new_x,new_y});
                        grid[new_x][new_y]=1;
                    }
                }
            }
            lvl++;
        }
        return -1;
    }
};
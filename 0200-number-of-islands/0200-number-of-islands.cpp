class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    void bfs(vector<vector<char>>&grid,int i, int j, int n, int m) {
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            
            for(auto &dir : directions) {
                int nr = dir[0]+r;
                int nc = dir[1] + c;
                if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc] != '#') {
                    if(grid[nr][nc] == '1') {
                        grid[nr][nc] = '#';
                        q.push({nr,nc});
                    }
                    
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == '1') {
                    bfs(grid,i,j,n,m);
                    grid[i][j] = '#';
                    islands++;
                }
            }
        }
        return islands;
    }
};
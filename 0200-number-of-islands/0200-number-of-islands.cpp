class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    void dfs(vector<vector<char>>&grid,vector<vector<int>>&vis,int n ,int m,int i,int j) { 
        vis[i][j] = 1;
        for(auto &dir : directions) {
            int new_i = i+dir[0];
            int new_j = j+dir[1];
            if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && grid[new_i][new_j] == '1' && vis[new_i][new_j]== 0) {
                dfs(grid,vis,n,m,new_i,new_j);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == '1' && vis[i][j] == 0) {
                    queue<pair<int,int>>q;
                    q.push({i,j});
                    vis[i][j] = 1;
                    while(!q.empty()) {
                        auto row = q.front().first;
                        auto col = q.front().second;
                        q.pop();
                        
                        for(auto &dir : directions) {
                            int new_i = row+dir[0];
                            int new_j = col+dir[1];
                            if(new_i>=0 && new_j>=0 && new_i<n && new_j<m && grid[new_i][new_j] == '1' && vis[new_i][new_j]== 0) {
                                q.push({new_i,new_j});
                                vis[new_i][new_j] =1;
                            }
                        }
                    }
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
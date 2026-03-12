class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1}};
    bool isValid(int i, int j, int n, int m) {
        return (i >= 0 && j >= 0 && i<n && j<m);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        queue<pair<int,int>>q;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                }else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int ans = 0;
        if(fresh == 0) return ans;
        while(!q.empty()) {
            int size = q.size();
            for(int k =0 ;k<size;k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for(auto &dir : directions) {
                    int new_i = i+dir[0];
                    int new_j = j + dir[1];
                    
                    if(isValid(new_i,new_j,n,m)) {
                        if(grid[new_i][new_j] == 1) {
                            
                            grid[new_i][new_j] = 2;
                            q.push({new_i, new_j});
                            fresh--;
                        }
                    }
                    
                }
                
            }
            ans++;
        }
        
        return fresh == 0 ? ans-1 : -1;
    }
};
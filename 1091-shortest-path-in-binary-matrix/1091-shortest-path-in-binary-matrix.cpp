class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{-1,1},{1,-1},{1,1}};
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();
        int m = grid[0].size();
        
        int dist = 0;
        queue<vector<int>>q;
        q.push({0,0,0});
        int minDist = INT_MAX;
        
        while(!q.empty()) {
            int size = q.size();
            for(int k = 0;k<size;k++) {
                int i = q.front()[0];
                int j = q.front()[1];
                int dist = q.front()[2];
                q.pop();
                if(i==n-1 && j == m-1) {
                    minDist = min(minDist,dist);
                    
                }
                for(auto &dir : directions) {
                    int new_i = i+dir[0];
                    int new_j = j+dir[1];
                    if(new_i >=0 && new_i<n && new_j>=0 && new_j<n && grid[new_i][new_j] == 0) {
                        q.push({new_i,new_j,dist+1});
                        grid[new_i][new_j] = -1;
                        
                    }
                }
            }
        }
        return minDist!=INT_MAX ? minDist+1 : -1;

    }
};
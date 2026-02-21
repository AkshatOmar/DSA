class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1},{1,1},{-1,1},{1,-1},{-1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1]==1) return -1;
        queue<pair<int,int>>q;
        //push i,j in queue
        q.push({0,0});
        //initialize sum for returning ansl
        int sum = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int k =0;k<size;k++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();
                
                if(i == n-1 && j == n-1) {
                    return sum+1;
                }
                for(auto &dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    if(new_i >=0 && new_i<n && new_j>=0 && new_j < n && grid[new_i][new_j] == 0) {
                        grid[new_i][new_j] = 1;
                        q.push({new_i,new_j});
                    }
                }
            }
            sum++;
        }
        return -1;
    }
};
class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1},{-1,-1},{1,1},{-1,1},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] != 0) {
            return -1;
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        while(!pq.empty()) {
            int dis = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for(auto &dir:directions) {
                int new_i = i+dir[0];
                int new_j = j+dir[1];
                if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && grid[new_i][new_j]==0) {
                    if(dis + 1< dist[new_i][new_j]){
                        dist[new_i][new_j] = dis+1;
                        pq.push({dis+1,{new_i,new_j}});
                        grid[new_i][new_j] = 1;
                    }
                }
            }
        }
        if(dist[n-1][m-1] == INT_MAX)
        return -1;

        return dist[n-1][m-1]+1;
    }
};
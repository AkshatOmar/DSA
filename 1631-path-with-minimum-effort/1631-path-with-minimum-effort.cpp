class Solution {
public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>>result(n,vector<int>(m,1e9));
        result[0][0] = 0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,0}});
        while(!pq.empty()) {
            int dist = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            for(auto &dir : directions) {
                int new_i = i+dir[0];
                int new_j = j+dir[1];
                
                if(new_i>=0 && new_i<n && new_j>=0 && new_j<m) {
                    int diff = abs(heights[new_i][new_j]-heights[i][j]);
                    int maxDiff = max(diff,dist);
                    if(maxDiff<result[new_i][new_j]) {
                        result[new_i][new_j] = maxDiff;
                        pq.push({maxDiff,{new_i,new_j}});
                    }
                }
            }
        }
        return result[n-1][m-1];
    }
};
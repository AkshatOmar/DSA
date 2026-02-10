class Solution {
public: 
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>res(n,vector<int>(m,-1));
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                if(mat[i][j] == 0) {
                    res[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()) {
            auto it = q.front();
            int i = it.first;
            int j = it.second;
            q.pop();
            for(auto &dir : directions) {
                int new_i = i+dir[0];
                int new_j = j+dir[1];
                if(new_i>=0 && new_i<n && new_j>=0 && new_j<m && res[new_i][new_j] == -1) {
                    res[new_i][new_j] = res[i][j] + 1;
                    q.push({new_i,new_j});
                }
            }
        }
        return res;
    }
};
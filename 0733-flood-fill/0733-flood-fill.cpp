class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    bool isSafe(vector<vector<int>>&image, int i,int j, int n, int m) {
        return (i>=0 && i<n && j>=0 && j<m);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
        int tgt = image[sr][sc];
        if(tgt == color) return image;
        image[sr][sc] = color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()) {
            int sz = q.size();
            for(int k = 0;k<sz;k++) {
                auto it = q.front();
                q.pop();
                int i = it.first;
                int j = it.second;
                for(auto& dir : directions) {
                    int new_i = i+dir[0];
                    int new_j = j + dir[1];
                    if(isSafe(image,new_i,new_j,n,m) && image[new_i][new_j] == tgt) {
                        image[new_i][new_j] = color;
                        q.push({new_i,new_j});
                    }
                }
            }
        }   
        return image;
    }
};
class Solution {
public:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        int ognl = image[sr][sc];
        if(ognl == color) return image;
        image[sr][sc] = color;
        queue<pair<int,int>>q;
        q.push({sr,sc});
        while(!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for(auto &dir : directions) {
                int new_i = dir[0]+i;
                int new_j = dir[1]+j;
                
                if(new_i>=0 && new_j>=0 && new_i<n && new_j<m) {
                    if(image[new_i][new_j] == ognl) {
                        image[new_i][new_j] = color;
                        q.push({new_i,new_j});
                    }
                }
            }
        }
        return image;
    }
};
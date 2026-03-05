class Solution {
private: 
vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
bool isValid(int new_i, int new_j, int n) {
    return new_i >=0 && new_i < n && new_j >= 0 && new_j < n;
}
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>>vis(n,vector<int>(n,0));
        //pq<int,vector,greater;-> 

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        //{t,{i,j}};
        pq.push({grid[0][0],{0,0}});
        vis[0][0] = 1;
        while(!pq.empty()) {
            int t = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
    
            if(i == n-1 && j == n-1) return t;

            for(auto &dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(isValid(new_i,new_j,n)) {
                    if(vis[new_i][new_j] == 0) {
                        pq.push({max(t,grid[new_i][new_j]),{new_i,new_j}});
                        vis[new_i][new_j] = 1;
                    }
                    
                }

            }
        }
        return -1;
    }
};
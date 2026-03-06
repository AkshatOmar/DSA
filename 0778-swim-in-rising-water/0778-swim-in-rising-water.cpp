class DSU {
    vector<int>rank, parent;
    public:
    DSU(int n) {
        rank.resize(n,0);
        parent.resize(n);
        for(int i = 0;i<n;i++) {
            parent[i] = i;
        }
    }
    int find(int i) {
        if(parent[i] == i){
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void unite(int u,int v) {
        int ul_u = find(u);
        int ul_v = find(v);
        if(ul_u == ul_v) return;
        if(rank[ul_v] >rank[ul_u]) {
            parent[ul_u] = parent[ul_v];
        }
        else if(rank[ul_v] < rank[ul_u]) {
            parent[ul_v] = parent[ul_u];
        }
        else {
            parent[ul_v] = ul_u;
            rank[ul_u]++;
        }
    }
};
class Solution {
private:
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    bool isValid(int i, int j, int n) {
        return (i>=0 && j<n && i<n && j>=0);
    }
public:
    int swimInWater(vector<vector<int>>& grid) { 
        int n = grid.size();
        DSU ds(n*n);
        vector<tuple<int,int,int>>cells;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                cells.push_back({grid[i][j],i,j});
            }
        }
        sort(cells.begin(),cells.end());
        vector<vector<int>>vis(n,vector<int>(n,0));
        for(auto &[h,i,j] : cells) {
            vis[i][j] = 1;
            for(auto &dir : directions) {
                int new_i = i + dir[0];
                int new_j = j + dir[1];

                if(isValid(new_i,new_j,n) && vis[new_i][new_j] == 1) {
                    ds.unite(i*n+j,new_i*n+new_j);
                }

            }
            if(ds.find(0) == ds.find(n*n-1)){
                return h;
            }
        }
        return -1;
    }

};
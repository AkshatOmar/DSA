class DSU {
    vector<int>size,parent;
public : 
    DSU(int n) {
        size.resize(n,1);
        parent.resize(n);
        for(int i =0;i<n;i++)  {
            parent[i] = i;
        }
    }
    int find(int i) {
        if(parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void unionBySize(int u, int v) {
        int new_u = find(u);
        int new_v = find(v);
        if(new_u == new_v) return;
        if(size[new_u] > size[new_v]) {
            parent[new_v] = new_u;
            size[new_u] += size[new_v];
        }
        else {
            parent[new_u] = new_v;
            size[new_v] += size[new_u];
        }
    }
    int getSize(int node) {
        return size[find(node)];
    }
};
class Solution {
private:
    vector<vector<int>>directions{{-1,0},{1,0},{0,-1},{0,1}};
    bool isValid(int i, int j ,int n) {
        return (i>=0 && i<n && j >= 0 && j<n);
    }
    void connectGrid(vector<vector<int>>&grid, int n,DSU &ds) {
        
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {

                if(grid[i][j] == 0) continue;

                for(auto &dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    if(isValid(new_i,new_j,n)) {
                        if(grid[new_i][new_j] == 1) {
                            int adjNode = new_i * n + new_j;
                            int node = i*n + j;
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }

            }
        }
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);
        connectGrid(grid,n,ds);
        int ans = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 1)continue;
                set<int>components;
                for(auto &dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    if(isValid(new_i,new_j,n)) {
                        if(grid[new_i][new_j] == 1) {
                            int adjNode = new_i * n + new_j;
                            components.insert(ds.find(adjNode));
                        }
                    }
                }
                int totalSize = 0;
                for(auto it : components) {
                    totalSize += ds.getSize(it);
                }
                ans = max(totalSize+1,ans);
            }
        }
        for(int i =0;i<n*n;i++) {
            ans = max(ds.getSize(ds.find(i)), ans);
        }
        return ans;
    }
};
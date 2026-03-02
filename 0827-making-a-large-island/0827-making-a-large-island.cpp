class DSU {
    vector<int>rank,parent,size;
    public:
    DSU(int n) {
        rank.resize(n,0);
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0;i<n;i++) {
            parent[i] = i;
        }
    }

    int find(int i) {
        if(parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
  
    }

    void unionByrank(int x,int y) {
        int new_x = find(x);
        int new_y = find(y);
        if(new_x == new_y) 
            return;
        
        if(rank[new_x] >rank[new_y]) {
            parent[new_y] = new_x;
        }

        else if(rank[new_x] <rank[new_y]) {
            parent[new_x] = new_y;
        }

        else {
            parent[new_x] = new_y;
            rank[new_y]++;
        }
    }
    void unionBySize(int x,int y) {
        int new_x = find(x);
        int new_y = find(y);

        if(size[new_x] < size[new_y]) {
            parent[new_x] = new_y;
            size[new_y] += size[new_x];
        }
        else {
            parent[new_y] = new_x;
            size[new_x] += size[new_y];
        }
    }
    int getSize(int x) {
        int root = find(x);
        return size[root];
    }
};
class Solution {
private: 
    bool isValid(int i,int j,int n) {
        return (i >= 0 && j>=0 && j<n && i<n);
    }
public:
    vector<vector<int>>directions{{1,0},{-1,0},{0,-1},{0,1}};
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DSU ds(n*n);
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 0)continue;
                int node = i*n + j;

                for(auto &dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    int adjNode = new_i * n + new_j;

                    if(isValid(new_i,new_j,n)) {

                        if(grid[new_i][new_j] == 1) {

                            //Connected the islands
                            if(ds.find(node) != ds.find(adjNode)) {
                                ds.unionBySize(node,adjNode);
                            }
                            
                        }

                    }

                }

            }
        }
        int ans = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(grid[i][j] == 1) continue;
                set<int>components;

                for(auto dir : directions) {
                    int new_i = i + dir[0];
                    int new_j = j + dir[1];
                    int adjNode = new_i * n + new_j;

                    if(isValid(new_i,new_j,n)) {
                        if(grid[new_i][new_j] == 1) {
                            components.insert(ds.find(adjNode));
                        }
                    }

                }
                int totalSize = 0;
                for(auto it : components) {
                    totalSize += ds.getSize(it);
                }
                ans = max(ans,totalSize+1);
            }
            
        }
        for(int i = 0;i<n*n;i++) {
                ans = max(ans,ds.getSize(ds.find(i)));
            }
        return ans;
    }
};
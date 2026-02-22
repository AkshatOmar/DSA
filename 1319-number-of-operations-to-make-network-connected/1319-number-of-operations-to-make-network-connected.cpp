class DSU {
    vector<int>parent,rank;
    public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n,0);
        for(int i =0;i<n;i++) {
            parent[i] = i;
        }
    }
    int find(int i) {
        if(parent[i] == i) {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void unionFind(int x, int y) {
        int new_x = find(x);
        int new_y = find(y);
        if(new_x == new_y)
            return;
        if(rank[new_x] > rank[new_y]) {
            parent[new_y] = new_x;
        }
        else if(rank[new_x] < rank[new_y]) {
            parent[new_x] = new_y;
        }
        else {
            parent[new_x] = new_y;
            rank[new_y]++;
        }
    }
};

class Solution {
public:
    void dfs(int node, vector<vector<int>>&adj, vector<int>&vis) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int avlConnections = connections.size();
        if(n-1 > avlConnections) return -1;
        int extracnt = 0;
        DSU ds(n);
        for(auto it : connections) {
            int a = it[0];
            int b = it[1];
            if(ds.find(a) == ds.find(b)) {
                extracnt++;
            }
            else {
                ds.unionFind(a,b);
                
            }
        }
        vector<vector<int>>adj(n);
        for(auto it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int components = 0;
        vector<int>vis(n,0);
        for(int i = 0;i<n;i++) {
            if(!vis[i]) {   
                dfs(i,adj,vis);
                components++;
            }
        }
        if(extracnt >= components-1) return components-1;
        return -1;
        
    }
};
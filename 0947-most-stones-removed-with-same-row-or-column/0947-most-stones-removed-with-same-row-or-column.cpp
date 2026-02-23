class DSU {
    vector<int>parent,rank;
    public : 
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
        void unite(int u,int v) {
            int ul_u = find(u);
            int ul_v = find(v);
            if(rank[ul_u] < rank[ul_v]) {
                parent[ul_u] = ul_v;
            }
            else if(rank[ul_u] > rank[ul_v]) {
                parent[ul_v] = ul_u;
            }
            else{
                parent[ul_v] = ul_u;
                rank[ul_u]++;
            }
        }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU ds(n);
        for(int i = 0;i<n-1;i++) {
            for(int j = i+1;j<n;j++) {
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ds.unite(i,j);
                }
            }
        }
        int components = 0;
        for(int i = 0;i<n;i++) {
            if(ds.find(i) == i) {
                components++;
            }
        }
        return n - components;
    }
};
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
        int maxRow = 0,maxCol = 0;
        for(auto it : stones) {
            maxRow = max(maxRow,it[0]);
            maxCol = max(maxCol,it[1]);
        }

        DSU ds(maxRow + maxCol+2);
        unordered_set<int>usedNodes;
        for(auto &s : stones) {
            int row  = s[0];
            int col = s[1]+maxRow+1;
            ds.unite(row,col);
            usedNodes.insert(row);
            usedNodes.insert(col);
        }
        int components = 0;
        for(auto nodes : usedNodes) {
            if(ds.find(nodes) == nodes) components++;
        }
        return n - components;
    }
};
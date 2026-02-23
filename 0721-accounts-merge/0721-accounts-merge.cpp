class DSU {
    vector<int>parent,rank;
    public:
        DSU(int n) {
            parent.resize(n);
            rank.resize(n,0);
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
        void unite(int u,int v) {
            int new_u = find(u);
            int new_v = find(v);
            if(new_u == new_v) {
                return;
            }
            if(rank[new_u] >rank[new_v]) {
                parent[new_v] = new_u;
            }
            else if(rank[new_u]< rank[new_v]) {
                parent[new_u] = new_v;
            }
            else {
                parent[new_u] = new_v;
                rank[new_v]++;
            }
        }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DSU ds(n);
        unordered_map<string,int>mapMailNode;
        for(int i = 0;i<n;i++) {
            for(int j = 1;j<accounts[i].size();j++) {
                string mail = accounts[i][j];
                if(mapMailNode.find(mail) == mapMailNode.end()) {
                    mapMailNode[mail] = i;
                }
                else {
                    ds.unite(i,mapMailNode[mail]);
                }
            }
        }

        vector<vector<string>>mergeMail(n);

        for(auto it : mapMailNode) {
            string mail = it.first;
            int nodes = ds.find(it.second);
            mergeMail[nodes].push_back(mail);
        }

        vector<vector<string>>ans;

        for(int i = 0;i<n;i++) {
            if(mergeMail[i].size() == 0) continue;
            sort(mergeMail[i].begin(),mergeMail[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it : mergeMail[i]) {
                temp.push_back(it);
            }
            ans.push_back(temp);

        }
        return ans;
    }
};
class Solution {
public:
    void dfs(vector<int>adj[], vector<bool>&vis,int i) {
        
        vis[i] = true;
        for(auto it: adj[i]) {
            if(!vis[it]) {
                dfs(adj,vis,it);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<bool>vis(v,false);
        vector<int>adj[v];
        int cnt = 0;
        for(int i = 0;i<v;i++) {
            for(int j = 0;j<v;j++) {
                if(isConnected[i][j] == 1 && i!=j) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for(int i = 0;i<v;i++) {
            if(!vis[i]) {
                cnt++;
                dfs(adj,vis,i);
            }
        }
        return cnt;
    }
};
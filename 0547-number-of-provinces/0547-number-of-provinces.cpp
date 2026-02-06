class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, vector<int>&vis,int i) {
        vis[i] = 1;
        for(int j = 0;j<isConnected.size();j++){
            if(vis[j] == 0 && isConnected[i][j] == 1) {
                dfs(isConnected,vis,j);
            }
        }
            
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        vector<int>vis(v,0);
        int cnt = 0;
        for(int i = 0;i<v;i++) {
            if(vis[i] == 0) {
                cnt++;
                dfs(isConnected,vis,i);
            }
        }
        return cnt;
    }
};
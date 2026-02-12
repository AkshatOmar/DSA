class Solution {
public:
    bool dfs(vector<vector<int>>&graph,vector<int>&vis,int col,int node) {
        vis[node] = col;
        for(auto adjNode:graph[node]) {
            if(vis[adjNode] == -1) {
                if(dfs(graph,vis,!col,adjNode) == false) return false;
            }
            else if(vis[adjNode] == col) {
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        //adj list is given
        int v = graph.size();
        vector<int>vis(v,-1);
        for(int i = 0;i<v;i++) {
            if(vis[i] == -1) {
                if(dfs(graph,vis,0,i) == false) return false;
            }
        }
        return true;
    }
};
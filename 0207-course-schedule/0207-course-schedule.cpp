class Solution {
public:
    bool dfs(int numCourses,vector<vector<int>>&adj,vector<int>&vis,int node) {
        if(vis[node] == 1)return true;
        if(vis[node] == 2) return false;
        vis[node] = 1;
        for(int adjnode:adj[node]) {
            if(dfs(numCourses,adj,vis,adjnode))return true;
        }
        vis[node] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //Build graph first;
        vector<vector<int>>adj(numCourses);
        for(auto &p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        //Now simply detect cucle in graph
        vector<int>vis(numCourses,0);
        for(int i = 0;i<numCourses;i++) {
            if(vis[i] == 0) {
                if(dfs(numCourses,adj,vis,i)) return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    bool dfs(int node, int numCourses, vector<vector<int>>&graph,vector<int>&vis,vector<int>&path) {
        vis[node] = 1;
        path[node] = 1;
        for(auto &adjNode: graph[node]) {
            if(vis[adjNode]==0) { 
                if(dfs(adjNode,numCourses,graph,vis,path)==true) return true;
            }
            else if(path[adjNode] == 1 && vis[adjNode] == 1) {
                return true;
            }
            
        }
        path[node] = 0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(int i = 0;i<prerequisites.size();i++) {
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            graph[u].push_back(v);
        }
        vector<int>vis(numCourses,0);
        vector<int>path(numCourses,0);
        for(int i = 0;i<numCourses;i++) {
            if(vis[i] == 0) {
                if(dfs(i,numCourses,graph,vis,path))return false;
            }
        }
        return true;
    }
};
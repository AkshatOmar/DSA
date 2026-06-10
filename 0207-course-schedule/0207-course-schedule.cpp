class Solution {
public:
    bool dfs(vector<vector<int>>&graph,int node,vector<int>&vis,vector<int>&path,int numCourses) {
        vis[node] = true;
        path[node] = true;
        for(auto it : graph[node]) {
            if(!vis[it]) {
                if(dfs(graph,it,vis,path,numCourses)) return true;
            }
            else if(path[it]) {
                return true;
            }
        }
        path[node] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        //build graph
        for(auto it : prerequisites) {
            graph[it[0]].push_back(it[1]);
        }
        vector<int>vis(numCourses,false);
        vector<int>path(numCourses,false);
        for(int i = 0;i<numCourses;i++) {
            for(auto it : graph[i]) {
                if(!vis[it]) {
                    if(dfs(graph,it,vis,path,numCourses)) return false;
                }
                
            }
        }
        return true;
    } 
};
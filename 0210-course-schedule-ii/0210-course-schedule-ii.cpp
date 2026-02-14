class Solution {
public:
    bool dfs(int node,vector<vector<int>>&graph,vector<int>&vis,vector<int>&path,stack<int>&st) {
        vis[node] = 1;
        path[node] = 1;
        for(auto adjNode : graph[node]) {
            if(vis[adjNode] == 0) {
                if(dfs(adjNode,graph,vis,path,st)){
                    return true;
                }
                
            }else if(path[adjNode] ==1) {
                return true;
            }
        }
        path[node] = 0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(auto &it: prerequisites) {
            graph[it[1]].push_back(it[0]);
        }
        vector<int>vis(numCourses,0);
        vector<int>path(numCourses,0);
        stack<int>st;
        for(int i = 0;i<numCourses;i++) {
            if(vis[i] == 0) {
                if(dfs(i,graph,vis,path,st)) return {};
            }
        }
        vector<int>ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
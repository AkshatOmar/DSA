class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<vector<int>>adj(V);
        vector<int>indegree(V,0) ;
        for(int i = 0;i<V;i++) {
            //now = i->it
            //we want it->i;
            for(int it : graph[i]) {
                adj[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q;
        for(int i = 0;i<V;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<bool> safe(V);
        vector<int>ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safe[node] = true;
            for(int adjNode : adj[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        for(int i = 0;i<V;i++) {
            if(safe[i]) ans.push_back(i);
        }
        return ans;
    }
};
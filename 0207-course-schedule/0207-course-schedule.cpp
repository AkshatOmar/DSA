class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(auto it : prerequisites) {
            int u = it[1];
            int v = it[0];
            graph[u].push_back(v);
        }
        queue<int>q;
        vector<int>indegree(numCourses);
        for(int i = 0;i<numCourses;i++) {
            for(auto it : graph[i]) {
                indegree[it]++;
            }
        }
        for(int i = 0;i<indegree.size();i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:graph[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        if(ans.size()!= numCourses) {
            return false;
        }
        return true;
    }
};
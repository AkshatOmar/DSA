class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        for(auto &it: prerequisites) {
            graph[it[1]].push_back(it[0]);
        }
        vector<int>indegree(numCourses,0);
        for(int i = 0;i<numCourses;i++) {
            for(auto &it:graph[i]) {
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i = 0;i<numCourses;i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int adjNode : graph[node]) {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0) {
                    q.push(adjNode);
                }
            }
        }
        if(ans.size() == numCourses)
            return ans;
        return {};
    }
};
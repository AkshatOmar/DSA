class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>graph(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto it : prerequisites) {
            graph[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        
        queue<int>q;
        for(int i = 0;i<numCourses;i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int cnt = 0;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            cnt++;
            for(auto it : graph[node]) {
                indegree[it]--;
                if(indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        return cnt == numCourses;
    }
};
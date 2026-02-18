class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>graph(n+1);
        //Create graph
        for(auto &it : times) {
            graph[it[0]].push_back({it[1],it[2]});
        }
        //initialize min heap pq;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        //declare a distance array
        vector<int>dist(n+1,1e9);
        dist[k] = 0;
        while(!pq.empty()) {
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();
            for(auto &it : graph[node]) {
                int adj = it.first;
                int wt = it.second;
                if(cost+wt < dist[adj]) {
                    dist[adj] = cost+wt;
                    pq.push({dist[adj],adj});
                }
            }
        }
        int ans = INT_MIN;
        for(int i=1;i<=n;i++) {
            if(dist[i] == 1e9) {
                return -1;
            }
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto it : roads) {
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        pq.push({0,0});
        vector<long long>dist(n,LLONG_MAX);
        dist[0] = 0;
        vector<int>ways(n,0);
        ways[0] = 1;
        int mod =  (1e9+7);
        while(!pq.empty()) {
            int node = pq.top().second;
            long long cost = pq.top().first;
            pq.pop();
            if(cost>dist[node])continue;
            for(auto it : graph[node]) {
                int adj = it.first;
                int wt = it.second;
                if(wt+cost < dist[adj]) {
                    dist[adj] = wt+cost;
                    ways[adj] = ways[node];
                    pq.push({dist[adj],adj});
                }
                else if(wt+cost == dist[adj]) {
                    ways[adj] = (ways[adj]+ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
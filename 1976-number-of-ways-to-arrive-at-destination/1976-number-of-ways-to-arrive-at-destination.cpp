class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>graph(n);
        for(auto it : roads) {
            graph[it[0]].push_back({it[1],it[2]});
            graph[it[1]].push_back({it[0],it[2]});
        }
        long long mod = 1e9+7;
        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > q;

        q.push({0,0});
        vector<long long>dist(n,LLONG_MAX);
        vector<long long>ways(n,0);
        dist[0] = 0;
        ways[0] = 1;
        while(!q.empty()) {
            long long cost = q.top().first;
            int node = q.top().second;
            q.pop();
            if(cost>dist[node]) continue;
            for(auto it : graph[node]) {
                int adj = it.first;
                long long wt = it.second;
                if(wt+cost<dist[adj]) {
                    dist[adj] = wt+cost;
                    ways[adj] = ways[node];
                    q.push({dist[adj],adj});
                }
                else if(wt + cost == dist[adj]) {
                    ways[adj] = (ways[adj] + ways[node])%mod;
                }
            }
        }
        return ways[n-1]%mod;
    }
};
class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        //Build the graph first
        vector<vector<pair<int,int>>>graph(n);
        for(auto it : flights) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            graph[u].push_back({v,wt});
        }
        // {stops,{node,wt}}
        queue<pair<int,pair<int,int>>>q;
        q.push({0,{src,0}});
        vector<int>dist(n,INT_MAX);
        dist[src] = 0;
        while(!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int cost = q.front().second.second;
            q.pop();
            if(stops>k) continue;
            for(auto it : graph[node]) {
                int adjNode = it.first;
                int wt = it.second;
                if(wt + cost < dist[adjNode] && stops<=k) {
                    dist[adjNode] = wt+cost;
                    q.push({stops+1,{adjNode,dist[adjNode]}});
                }
            }
        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};
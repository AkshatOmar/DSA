class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto &it : times) {
            adj[it[0]].push_back({it[1],it[2]});
        }
        
        
        priority_queue<pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>>pq;
        vector<int>dist(n+1,INT_MAX);

        dist[k] = 0;
        pq.push({0,k});
        
        while(!pq.empty()) {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if(dist[node] < d) {
                continue;
            }
            for(auto &it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                if(wt+d<dist[adjNode]) {
                    dist[adjNode] = wt + d;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int ans = INT_MIN;
        for(int i = 1;i<dist.size();i++) {
            if(dist[i] == INT_MAX) return -1;
            ans = max(ans,dist[i]);
        }
        return ans;
    }
};
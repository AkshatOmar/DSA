class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &it : flights) {
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<vector<int>>dist(n,vector<int>(k+2,INT_MAX));
        dist[src][0] = 0;
        priority_queue<vector<int>,
                    vector<vector<int>>,
                    greater<vector<int>>>pq;
        pq.push({0,0,src});
        while(!pq.empty()) {
            int stops = pq.top()[0];
            int d = pq.top()[1];
            int node = pq.top()[2];
            pq.pop();
            if(stops>k)continue;
            for(auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;
                if(d + wt < dist[adjNode][stops+1]) {
                    dist[adjNode][stops+1] = d+wt;
                    pq.push({stops + 1,dist[adjNode][stops+1],adjNode});
                }
            }

        }
         
        int ans = INT_MAX;
        for(int i = 1;i<=k+1;i++) {
            ans = min(ans,dist[dst][i]);
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
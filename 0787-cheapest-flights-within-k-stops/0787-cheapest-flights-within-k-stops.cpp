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
        queue<pair<int,int>>q;
        q.push({0,src});
        vector<int>dist(n,INT_MAX);
        int stops = 0;
        dist[src] = 0;
        while(!q.empty() && stops<=k) {
            
            int size = q.size();
            vector<int>temp = dist;
            while(size--) {
                int cost = q.front().first;
                int node = q.front().second;
                int size = q.size();
                q.pop();
                for(auto it : graph[node]) {
                    int adj = it.first;
                    int wt = it.second;

                    if(wt+cost<temp[adj]) {
                        temp[adj] = wt+cost;
                        q.push({cost+wt,adj});
                    }

                }
            }
            dist=temp;
            stops++;
        } 
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
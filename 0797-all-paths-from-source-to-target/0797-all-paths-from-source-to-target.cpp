class Solution {
public:
    void dfs(int node,int n,vector<vector<int>>&graph,vector<vector<int>>&ans,vector<int>&temp) {
        temp.push_back(node);
        if(node == n-1) {
            ans.push_back(temp);
            return;
        }
        for(int adj : graph[node]) {
            dfs(adj,n,graph,ans,temp); 
            temp.pop_back();
        }
        
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>temp;
        int n = graph.size();
        dfs(0,n,graph,ans,temp);
        return ans;
    }
};
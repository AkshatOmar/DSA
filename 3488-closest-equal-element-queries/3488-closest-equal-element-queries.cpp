class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        int m = queries.size();
        vector<int>ans;
        unordered_map<int,vector<int>>mp;
        //took map to store nums[i] and their index of occurances
        for(int i = 0;i<n;i++) {
            mp[nums[i]].push_back(i);
        }
        
        for(int i = 0;i<m;i++) {
            int num = nums[queries[i]];
            vector<int>&v = mp[num];
            int s = queries[i];
            if(v.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            int k = v.size();
            auto p = lower_bound(v.begin(),v.end(),s)-v.begin();
            int mini = INT_MAX;
            if(p+1<k){
                mini=min({mini,v[p+1]-v[p], n-(v[p+1]-v[p])});
            }
            if(p-1>=0){
                mini=min({mini,v[p]-v[p-1], n-(v[p]-v[p-1])});
            }
            if(p==0){
                mini=min({mini,v[p+1]-v[p], n-(v[k-1]-v[0])});
            }
            if(p==k-1){
                mini=min({mini,v[p]-v[p-1], n-(v[p]-v[0])});
            }
            ans.push_back(mini);

        }
        return ans;
    }
};
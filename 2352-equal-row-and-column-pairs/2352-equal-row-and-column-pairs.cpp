class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        map<vector<int>,int>mp;
        for(int i = 0;i<n;i++) {
            mp[grid[i]]++;
        }
        int cnt = 0;
        for(int i=0;i<m;i++) {
            vector<int>v;
            for(int j = 0;j<n;j++) {
                v.push_back(grid[j][i]);
            }
            if(mp.count(v) > 0) {
                cnt += mp[v];
            }

        }
        return cnt;
    }
};
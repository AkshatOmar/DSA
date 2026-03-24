class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long m = grid[0].size();
        
        vector<int>pref(m*n,1);
        vector<long long>arr(n*m);
        int mod = 12345;
        int ind = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                arr[ind++]=grid[i][j];
            }
        }
        for(int i = 1;i<n*m;i++) { 
            pref[i] = (pref[i-1]*arr[i-1])%mod;
        }
        
        vector<int>suff(m*n,1);

        for(int i = n*m-2 ;i>=0 ; i--) {
            suff[i] = (suff[i+1] * arr[i+1]) % mod;
        }

        vector<vector<int>>ans(n,vector<int>(m));
        int idx = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<m;j++) {
                ans[i][j] = (pref[idx] * suff[idx])%mod;
                idx++;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool helper(vector<int>&arr, int idx, int n,vector<int>&vis) {
        if(idx >= n || idx < 0 || vis[idx]) return false;
        if(arr[idx] == 0) return true;
        vis[idx] = 1;
        bool fwd = helper(arr,idx+arr[idx],n,vis);
        bool bwd = helper(arr,idx-arr[idx],n,vis);
        return fwd || bwd;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<int>vis(n,0);
        return helper(arr,start,n,vis);
    }
};
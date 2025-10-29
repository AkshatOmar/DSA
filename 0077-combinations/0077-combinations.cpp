class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>&temp,int n, int k,int idx) {
        if(temp.size() == k) {
            res.push_back(temp);
            return;
        }
        for(int i = idx;i<=n;i++) {
            temp.push_back(i);
            helper(res,temp,n,k,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        vector<int>temp;
        helper(res,temp,n,k,1);
        return res;
    }
};
class Solution {
public:
    void helper(vector<vector<int>>&ans, vector<int>&temp, int k, int n, int sum,int idx) {
        if(temp.size() == k && sum == n){
            ans.push_back(temp);
            return;
        }
        if(sum>n || temp.size()>k) return;
        for(int i = idx;i<=9;i++) {
            if(sum>n) break;
            temp.push_back(i);
            helper(ans, temp,k,n,sum+i,i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>temp;
        helper(ans,temp, k, n,0,1);
        return ans;
    }
};
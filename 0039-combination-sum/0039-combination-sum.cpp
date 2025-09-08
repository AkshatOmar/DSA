class Solution {
public:
    void helper(vector<int>&candidates,int target,vector<vector<int>>&ans,vector<int>temp, int idx, int sum) {
        if(sum == target) {
            ans.push_back(temp);
            return;
        }
        if(sum > target || idx >= candidates.size()) {
            return;
        }
        temp.push_back(candidates[idx]);
        helper(candidates, target, ans, temp,idx, sum+candidates[idx]);
        temp.pop_back();
        helper(candidates, target, ans, temp,idx+1, sum);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int> temp;
        helper(candidates, target, ans, temp,0,0);
        return ans;
    }
};
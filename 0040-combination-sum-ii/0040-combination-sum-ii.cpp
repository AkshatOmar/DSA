class Solution {
public:
    void helper(vector<vector<int>>&res, vector<int>&temp,vector<int>& candidates, int target, int sum, int idx) {
        if(sum == target) {
            res.push_back(temp);
            return;
        }
        if(sum>target) return;
        for(int i = idx;i<candidates.size();i++) {
            if(i>idx && candidates[i] == candidates[i-1]) continue;
            temp.push_back(candidates[i]);
            helper(res, temp,candidates,target,sum+candidates[i],i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int>temp;
        sort(candidates.begin(), candidates.end());
        helper(res, temp,candidates,target, 0,0);
        return res;
    }
};
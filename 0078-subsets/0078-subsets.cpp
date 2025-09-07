class Solution {
public:
    void helper(vector<int>&nums,vector<vector<int>>&res,int idx,vector<int>&temp ){
        if(idx>=nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        helper(nums,res, idx+1,temp);
        temp.pop_back();
        helper(nums,res,idx+1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>temp;
        helper(nums, res, 0,temp);
        return res;
    }
};
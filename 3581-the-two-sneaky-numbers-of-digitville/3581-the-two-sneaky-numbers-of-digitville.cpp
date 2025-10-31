class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int>res;
        int prev = 0;
        int curr = 1;
        while(curr<n) {
            if(nums[prev] == nums[curr]) {
                res.push_back(nums[prev]);
            }
            prev++;
            curr++;
        }
        return res;
    }
};
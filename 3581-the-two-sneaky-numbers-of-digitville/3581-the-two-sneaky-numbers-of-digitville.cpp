class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>res;
        unordered_map<int,int>mp;
        for(auto& num : nums) {
            mp[num]++;
        }
        for(auto& [key, value] : mp) {
            if(value>1) {
                res.push_back(key);
            }
        }
        return res;
    }
};
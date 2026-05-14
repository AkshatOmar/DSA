class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto num : nums) {
            if(num < 1 || num > n-1) return false;
            mp[num]++;
        }
        
        for(int i = 1;i<n-1;i++){
            if(mp[i] != 1) return false;
        }        
        return mp[n-1] == 2;
    }
};
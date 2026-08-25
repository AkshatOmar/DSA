class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_set<int>mp;
        for(int &it : nums){ 
            mp.insert(it);
        }
        int i = 1;
        while(mp.find(i*k)!=mp.end()) {
            i++;
        }
        return i*k;
    }
};
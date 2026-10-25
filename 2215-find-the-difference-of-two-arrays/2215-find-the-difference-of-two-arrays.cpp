class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>>ans(2);
        unordered_set<int>st1;
        unordered_set<int>st2;
        for(int it : nums1) {
            st1.insert(it);
        }
        
        for(int it : nums2) {
            st2.insert(it);
        }
        for(int it : st1) {
            if(st2.find(it) == st2.end()) {
                ans[0].push_back(it);
            }
        }
        for(int it : st2) {
            if(st1.find(it) == st1.end()) {
                ans[1].push_back(it);
            }
        }
        return ans;
    }
};
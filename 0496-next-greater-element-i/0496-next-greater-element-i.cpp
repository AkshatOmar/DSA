class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int>ans(n,-1);
        unordered_map<int,int>mp;
        for(int i = 0;i<m-1;i++) {
            for(int j = i+1;j<m;j++) {
                if(nums2[i] < nums2[j]) {
                    mp[nums2[i]] = nums2[j];
                    break;
                }
            }
        }
        for(int i = 0;i<n;i++) {
            if(mp.count(nums1[i])) {
                ans[i] = mp[nums1[i]];
            }
        }
        return ans;
    }
};
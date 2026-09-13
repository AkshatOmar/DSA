class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        int n = nums1.size();
        int n2 = nums2.size();
        stack<int>st;
        for(int i=n2-1;i>=0;i--) {
            while(!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            mp[nums2[i]] = !st.empty() ? st.top() : -1;
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i = 0;i<n;i++) {
            
            ans.push_back(mp[nums1[i]]);
            
        }
        return ans;
    }
};
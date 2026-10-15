class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int i = 0;i<n;i++) {
            unordered_set<int>st;
            for(int j = i;j<n;j++) {
                for(int k = i;k<=j;k++) {
                    st.insert(nums[k]);
                }
                ans += (st.size()*st.size());
            }
        }
        return ans;
    }
};
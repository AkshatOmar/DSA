class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0,j=k;
        multiset<int>st;
        int currMax = nums[0];
        vector<int>ans;
        for(int i = 0;i<k;i++) {
            st.insert(nums[i]);
            currMax = max(currMax,nums[i]);
        }
        ans.push_back(currMax);
        while(j<n) {
            st.erase(st.find(nums[i]));
            st.insert(nums[j]);
            if(nums[j] > currMax) {
                currMax = nums[j];
            }
            ans.push_back(*st.rbegin());
            
            i++;
            j++;
        }
        return ans;
    }
};
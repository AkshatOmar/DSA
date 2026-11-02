class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MAX;
        for(int i = 0;i<n;i++) {
            long long mini = 0;
            for(int j = 0;j<n;j++) {
                mini += abs(nums[j]-nums[i]);
            }
            if(mini<ans) {
                ans = mini;
            }
        }
        return ans;
    }
};
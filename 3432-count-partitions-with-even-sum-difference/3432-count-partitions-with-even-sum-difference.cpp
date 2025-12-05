class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), totSum = 0;
        for(int i =0;i<n;i++) {
            totSum +=nums[i];
        }
        if(totSum %2 == 0) return n-1;
        return 0;
    }
};
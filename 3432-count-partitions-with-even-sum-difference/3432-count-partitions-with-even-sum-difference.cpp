class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), totSum = 0;
        for(int i =0;i<n;i++) {
            totSum +=nums[i];
        }
        int left = 0, right = 0;
        int cnt = 0;
        for(int i =0;i<n-1;i++) {
            left +=nums[i];
            right = totSum-left;
            if((left-right)%2 == 0) cnt++;
        }
        return cnt;
    }
};
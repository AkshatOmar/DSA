class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        int jump = 0;
        for(int i = 0;i<n;i++) {
            if(nums[i]+i > jump) {
                jump = nums[i]+i;
            }
            if(jump == n-1) return true;
            if(i >= jump) {
                return false;
            }
        }
        
        return true;
    }
};
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int num1 = INT_MAX,num2 = INT_MAX;
        while(i<n) {
            if(nums[i]<=num1) {
                num1 = nums[i];
            }
            else if(nums[i]<=num2) {
                num2 = nums[i];
            }
            else {
                return true;
            }
            
            i++;
        }
        return false;
    }
};
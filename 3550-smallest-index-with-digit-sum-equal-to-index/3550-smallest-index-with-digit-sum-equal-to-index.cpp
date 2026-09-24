class Solution {
public:
    int func(int num) {
        int sum = 0;
        while(num > 0) {
            int digit = num%10;
            sum += digit;
            num /= 10;
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0;i<n;i++) {
            int sum = func(nums[i]);
            if(sum == i) {
                return i;
            }
        }
        return -1;
    }
};
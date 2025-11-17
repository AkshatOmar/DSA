class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int gap = 0;
        for(int i =0;i<n;i++) {
            if(nums[i] == 1) {
                left = i;
                break;
            }
        }
        int right = left+1;
        while(left<= right&&right<n) { 
            if(nums[right] == 0){
                gap++;
                right++;
            }
            else if(nums[right] == 1){ 
                if(gap<k) return false;
                left = right;
                right++;
                gap = 0;
            }
        }
        return true;
    }
};
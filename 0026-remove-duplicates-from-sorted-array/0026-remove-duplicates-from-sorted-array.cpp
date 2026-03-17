class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int idx = 0;
        for(int i = 0;i<n;i++) {
            if(nums[i] != nums[idx]){
                idx++;
                nums[idx] = nums[i];
                
            }
        }
        return idx+1;
    }
};
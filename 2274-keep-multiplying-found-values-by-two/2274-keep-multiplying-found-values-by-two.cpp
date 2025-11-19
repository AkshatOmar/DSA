class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        int og = original;
        sort(nums.begin(),nums.end());
        for(int i =0;i<nums.size();i++){
            if(nums[i] == og){
                og =2*og;
            }
        }
        return og;
    }
};
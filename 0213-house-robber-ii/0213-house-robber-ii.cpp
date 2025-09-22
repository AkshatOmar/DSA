class Solution {
public:
    int helper(vector<int>&nums) {
        int prev2=0;
        int prev = nums[0];
        for(int i = 1;i<nums.size();i++) {
            int take = nums[i];
            if(i>1) take+=prev2;
            int nontake = 0+prev;
            int curri = max(take,nontake);
            prev2 = prev;
            prev = curri;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        
        int n = nums.size();
        if(n == 1)return nums[0];
        vector<int>temp1,temp2;
        for(int i = 0;i<n;i++) {
            if(i != 0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }

        return max(helper(temp1),helper(temp2));
    }
};
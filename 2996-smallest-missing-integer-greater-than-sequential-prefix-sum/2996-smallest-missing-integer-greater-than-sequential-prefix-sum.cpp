class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int sum = nums[0];
        for(int i = 0;i<n;i++) {
            mp[nums[i]]++;
        }
        for(int i = 1;i<n;i++) {
            if(nums[i] == nums[i-1]+1) {
                sum += nums[i];
            }else {
                break;
            }
        }
        while(mp.count(sum)) {
            sum++;
        }
        return sum;
    }
};
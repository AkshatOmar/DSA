class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int largest = INT_MIN;
        for(int i = 0;i<n;i++) {
            largest = max(largest,nums[i]);
            mp[nums[i]]++;
        }
        if(k == n) return largest;
        if(k == 1) {
            int maxi = INT_MIN;
            for(auto it : mp) {
                if(it.second == 1) {
                    maxi = max(maxi,it.first);
                }
            }
            return maxi == INT_MIN ? -1 : maxi;
        }
        if(mp[nums[0]] == 1 && mp[nums[n-1]] == 1) {
            return max(nums[0],nums[n-1]);
        }
        else if(mp[nums[0]] != 1 && mp[nums[n-1]] == 1) {
            return nums[n-1];
        }
        else if(nums[0] == nums[n-1]) return -1;
        else if(mp[nums[0]] == 1 && mp[nums[n-1]] != 1) {
            return nums[0];
        }
        return -1;
    }
};
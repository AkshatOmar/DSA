class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        for(int i = 0;i<n;i++) {
            for(int j = i;j<n;j++) {
                for(int k = j;k<n;k++) {
                    if(nums[i] == nums[j] && nums[j] == nums[k] && nums[k] == nums[i]&& i!= j && j!=k&&k!=i) {
                        mini = min(mini,abs(i-j)+abs(j-k)+abs(k-i));
                    }
                }
            }
        }
        return mini == INT_MAX ? -1 : mini;
    }
};
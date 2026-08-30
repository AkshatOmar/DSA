class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int maxi = INT_MIN;
        int mini = INT_MAX;
        int minEl = INT_MAX;
        int maxEl = INT_MIN;
        for(int i = 0;i<n;i++) {
            if(nums[i] > maxEl) {
                maxEl = nums[i];
                maxi = i;
            }
            if(nums[i]<minEl) {
                minEl = nums[i];
                mini = i;
            }
        }
        int bothFront = max(mini,maxi) +1;
        int bothBack = n - min(mini,maxi);
        int frontnBack = (min(mini,maxi) + 1) + (n-max(mini,maxi));

        return min({bothFront,bothBack,frontnBack});
    }
};
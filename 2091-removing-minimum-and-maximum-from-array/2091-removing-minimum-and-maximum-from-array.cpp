class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int minIdx = INT_MAX;
        int maxIdx = INT_MIN;
        for(int i = 0;i<n;i++) {
            if(nums[i] <mini) {
                mini = nums[i];
                minIdx = i;
            }
           if(nums[i] > maxi) {
                maxi = nums[i];
                maxIdx = i;
           }
        }
        int frontDist = max(maxIdx,minIdx)+1;
        int backDist = n- min(maxIdx, minIdx);
        int bothDist = (min(maxIdx,minIdx) + 1) +(n-max(maxIdx,minIdx));

        return min({frontDist,backDist,bothDist});
    }
};
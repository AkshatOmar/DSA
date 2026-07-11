class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0,j = 0;
        int flip = 0;
        int dist = 0;
        while(j<n) {
            if(nums[j] == 0) {
                flip++;
            }
            while(flip>k) {
                if(nums[i] == 0) {
                    flip--;
                }
                i++;
            }
            dist = max(dist,j-i+1);
            j++;
        }
        return dist;
    }
};
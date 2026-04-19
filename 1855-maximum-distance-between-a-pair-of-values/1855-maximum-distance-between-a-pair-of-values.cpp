class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i = 0, j = 0;
        int maxDist = INT_MIN;
        while(i<n && j<m) {
            if(nums1[i] > nums2[j]) {
                i++;
                j++;
            }
            else if(nums1[i] <= nums2[j]) {
                maxDist = max(maxDist,j-i);
                j++;
            }
            
        }
        return maxDist == INT_MIN ? 0 : maxDist;
    }
};
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0, j =n-1;
        int maxi = INT_MIN;
        int maxj = INT_MIN;
        int maxwtr = INT_MIN;
        while(j>i) {
            maxi = max(height[i],maxi);
            maxj = max(height[j],maxj);
            maxwtr = max(maxwtr, min(height[i],height[j])*(j-i));
            if(height[i] < height[j]) {
                i++;
            }
            else {
                j--;
            }
        }
        return maxwtr;
    }
};
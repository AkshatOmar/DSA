class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left =0;
        int right = n-1;
        int area = 0;
        while(left<right) {
            area = max(area,min(height[left],height[right]) * (right - left));
            if(height[left]>height[right]) right--;
            else if(height[left]<height[right]) left++;
            else {
                left++;
                right--;
            }
        }
        return area;
    }
};
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int ans = 0;
        vector<int>prefMax(n);
        vector<int>suffMax(n);
        prefMax[0] = height[0];
        suffMax[n-1] = height[n-1];
        for(int i =1;i<n;i++) {
            prefMax[i] = max(height[i], prefMax[i-1]); 
        }
        for(int i =n-2;i>=0;i--) {
            suffMax[i] = max(height[i],suffMax[i+1]);
        }

        for(int i = 0;i<n;i++) {
            ans += min(prefMax[i],suffMax[i]) - height[i];
        }
        return ans;
    }
};
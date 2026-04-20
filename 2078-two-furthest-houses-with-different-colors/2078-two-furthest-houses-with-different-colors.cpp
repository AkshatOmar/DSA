class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int maxDist = INT_MIN;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<n;j++) {
                if(i != j && colors[i] != colors[j]) {
                    maxDist = max(maxDist,abs(i-j));
                }
            }
        }
        return maxDist;
    }
};
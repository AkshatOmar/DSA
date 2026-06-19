class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int peak = 0;
        int sum = 0;
        int maxi = INT_MIN;
        for(int i = 0;i<n;i++) {
            sum += gain[i];
            peak = max(0,sum);
            maxi = max(maxi,peak);
        }
        return maxi;
    }
};
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        int hc = 1;
        int vc = 1;
        long long ans = 0;        

        sort(verticalCut.begin(),verticalCut.end(),greater<int>());
        sort(horizontalCut.begin(),horizontalCut.end(),greater<int>());

        int i = 0;
        int j = 0;

        while(i < m-1 && j < n-1) {
            if(horizontalCut[i] >= verticalCut[j]) {
                hc++;
                ans += horizontalCut[i]*vc;
                i++;
            }
            else {
                vc++;
                ans += verticalCut[j] * hc;
                j++;
            }
        }
        while(i < m-1) {
            hc++;
            ans += horizontalCut[i]*vc;
            i++;
        }
        while(j < n-1) {
            vc++;
            ans += verticalCut[j]*hc;
            j++;
        }
        return ans;
    }
};
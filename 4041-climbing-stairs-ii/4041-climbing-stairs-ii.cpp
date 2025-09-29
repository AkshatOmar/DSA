class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        int dp1 = 0;
        int dp2 = 0;
        int dp3 = 0;
        for(int i = 1;i<=n;i++) {
            int curr = INT_MAX;
            if(i-1>=0) {
                curr = min(curr,dp3 + costs[i-1]+1*1);
            }
            if(i-2>=0) {
                curr = min(curr,dp2+costs[i-1]+2*2);
            }
            if(i-3>=0) {
                curr = min(curr,dp1+costs[i-1]+3*3);
            }
            dp1 = dp2;
            dp2 = dp3;
            dp3 = curr;
        }
        return dp3;
    }
};
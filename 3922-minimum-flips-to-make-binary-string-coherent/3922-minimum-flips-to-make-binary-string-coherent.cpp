class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        if(n<3) return 0;
        int ones = 0;
        for(int i = 0;i<n;i++) {
            if(s[i] == '1')ones++;
        }
        int zeros = n- ones;
        int ans = n;
        //case 1: all zeros or all 1 ka min;
        ans = min(ones,zeros);
        // case 2 : exactly one 1 abs(ones-1) covers case when all zeros
        ans = min(ans,abs(ones-1));
        //case 3 : 1....1
        int cost = 0;
        if(s[0] == '0') cost ++;
        if(s[n-1] == '0') cost ++;

        for(int i = 1;i<n-1;i++) {
            if(s[i] == '1')cost++;
        }
        ans = min(ans,cost);
        return ans;
    }
};
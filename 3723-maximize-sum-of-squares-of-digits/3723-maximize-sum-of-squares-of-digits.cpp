class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum>num*9 || sum<0) return "";
        string ans = "";
        for(int i = 0;i<num;i++) {
            int remaining = num-1-i;
            for(int d = 9;d>=0;d--) {
                if(sum-d >=0 && sum-d <= remaining*9) {
                    ans += to_string(d);
                    sum-=d;
                    break;
                }
            }
        }
        return ans;
    }
};
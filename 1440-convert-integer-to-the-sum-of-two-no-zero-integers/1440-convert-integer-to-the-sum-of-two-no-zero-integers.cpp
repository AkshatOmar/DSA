class Solution {
public:
    bool isZero(int num) {
        while(num>0) {
            int digit = num%10;
            if(digit == 0)return true;
            num = num/10;

        }
        return false;
    }
    vector<int> getNoZeroIntegers(int n) {
        int b = n-1;
        for(int i = 1;i<n;i++) {
            if(i+b == n && !isZero(i)&& !isZero(b)) {
                return {i,b};
            }
            //a++;
            b--;
        }
        return {};
    }
};
class Solution {
public:
    bool checkDivisibility(int n) {
        
        int num = n;
        int val = n;
        int sum = 0;
        int prod = 1;
        while(num>0) {
            int digit = num%10;
            sum += digit;
            num /= 10;
        }
        while(val > 0) {
            int digit = val % 10;
            prod *= digit;
            val /= 10;
        }
        return (n%(sum+prod)==0);

    }
};
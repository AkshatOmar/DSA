class Solution {
public:
    bool isPrime(int num) {
        if(num<2) return false;
        for(int i = 2;i*i<=num;i++) {
            if(num%i == 0) return false;
        }
        return true;
    }
    int countBits(int i) {
        int cnt = 0;
        while(i>0) {
            if(i%2 == 1) cnt++;
            i = i/2;
        }
        return cnt;
    }
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i = left;i<=right;i++) {
            int count = countBits(i);
            if(isPrime(count)) {
                ans++;
            }
        }
        return ans;
    }
};
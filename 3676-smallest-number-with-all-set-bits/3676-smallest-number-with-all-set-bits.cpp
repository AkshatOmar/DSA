class Solution {
public:
    int smallestNumber(int n) {
        int cnt = 0;
        int ans = 0;
        while(n>0){
            n = n/2;
            cnt++;
        }
        while(cnt>=0){
            ans += pow(2,cnt-1);
            cnt--;
        }
        return ans;
    }
};
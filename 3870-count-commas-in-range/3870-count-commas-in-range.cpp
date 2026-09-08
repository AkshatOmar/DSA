class Solution {
public:
    int countCommas(int n) {
        
        int cnt = 0;
        for(int i = 1;i<=n;i++) {
            int dgt = 0;
            int temp = i;
            while(temp>0){
                dgt++;
                temp/=10;
            }
            cnt += (dgt-1)/3;
        }
        return cnt;
    }
};
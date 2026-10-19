class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(m == 1 && flowerbed[0] == 0 && n == 1) {
            flowerbed[0] = 1;
            return true;
        }
        if(n>0 && flowerbed[0] == 0 && flowerbed[1] == 0) {
            flowerbed[0] = 1;
            n--;
        }
        for(int i = 1;i<m-1;i++) {
            if(flowerbed[i] == 0) {
                if(flowerbed[i-1] == 0 && flowerbed[i+1] == 0) {
                    flowerbed[i] = 1;
                    n--;
                }
                if(n==0) return true;
            }

        }
        if(n>0 && flowerbed[m-1]==0 && flowerbed[m-2] == 0) {
            flowerbed[m-1] = 1;
            n--;
        }
        if(n>0) return false;
        return true;

    }
};
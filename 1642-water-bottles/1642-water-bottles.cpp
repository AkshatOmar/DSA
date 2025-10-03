class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int empty = numBottles;
        int full = numBottles;
        int ans = numBottles;
        while(empty>=numExchange) {
            full = empty/numExchange;
            empty = empty - full*numExchange + full;
            ans += full;
            full = 0;
        }
        return ans;
    }
};
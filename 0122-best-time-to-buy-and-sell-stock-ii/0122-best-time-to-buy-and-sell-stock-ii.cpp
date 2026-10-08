class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int buy = INT_MAX, sell = INT_MIN,sum = 0;
        for(int i = 0;i<n;i++) {
            buy = min(buy,prices[i]);
            sell = max(buy,prices[i]);
            if(sell-buy > 0) {
                sum += sell-buy;
                buy = sell;
                sell = INT_MIN;
            }
        }
        return sum;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sell = INT_MIN;
        int buy = INT_MAX;
        int maxProfit = INT_MIN;
        for(int i = n-1;i>=0;i--) {
            buy = prices[i];
            sell = max(prices[i],sell);
            maxProfit = max(maxProfit, sell-buy);
        }
        return maxProfit;
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        int currMax = prices[n-1];
        for(int i = n-2;i>=0;i--) {
            if(prices[i] > currMax) {
                currMax = prices[i];
            }
            if(currMax-prices[i] > maxProfit) {
                maxProfit = currMax-prices[i];
            }
        }
        return maxProfit;
    }
};
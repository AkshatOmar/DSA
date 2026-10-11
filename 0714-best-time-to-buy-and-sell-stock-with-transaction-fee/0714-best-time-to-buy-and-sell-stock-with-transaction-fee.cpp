class Solution {
public:
    
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        int profit = 0;
        int buy = prices[0];
        for(int i =1 ;i<n;i++) {
            buy = min(buy,prices[i]);
            if(prices[i] - buy-fee > 0) {
                profit += prices[i]-buy-fee;
                buy = prices[i]-fee;
                
            }
            
        }
        return profit;
    }
};
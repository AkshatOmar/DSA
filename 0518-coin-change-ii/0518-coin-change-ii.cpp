class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int>prev(amount+1,0);
        vector<unsigned int>curr(amount+1,0);
        for(int T = 0;T<=amount;T++) {  
            if(T%coins[0] == 0)prev[T] = 1;
            else prev[T] = 0;
        }
        for(int idx = 1;idx<n;idx++) {
            for(int T = 0;T<=amount;T++) {
                unsigned int nonpick = prev[T];
                unsigned int pick =  0;
                if(coins[idx] <= T) {
                    pick =curr[T-coins[idx]];
                }
                curr[T] = pick+nonpick;
                
            }
            prev = curr;
        }
        return (int)prev[amount];
    }
};
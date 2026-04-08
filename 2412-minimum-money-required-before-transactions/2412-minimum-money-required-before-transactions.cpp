class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        int n = transactions.size();
        vector<pair<int,int>>profit;
        vector<pair<int,int>>loss;

        for(auto &it : transactions) {
            long long cost = it[0];
            long long cashback = it[1];
            if(cashback >= cost) {
                profit.push_back({cost,cashback});
            }
            else {
                loss.push_back({cashback,cost});
            }
        }
        sort(profit.begin(),profit.end(), greater<pair<int,int>>());
        sort(loss.begin(), loss.end());
        
        long long ans = INT_MIN;
        long long curr = 0;
        for(auto &it : loss) {
            long long cost = it.second;
            long long cashback = it.first;
            curr += cost;
            ans = max(ans, curr);
            curr -= cashback;
        }
        for(auto &it : profit) {
            long long cost = it.first;
            long long cashback = it.second;
            curr+= cost;
            ans = max(ans, curr);
            curr -= cashback;
        }
        return ans;

    }
};
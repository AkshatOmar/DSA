class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        int n = transactions.size();
        vector<pair<int,int>>profit;
        vector<pair<int,int>>loss;

        for(auto it : transactions) {
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
        for(auto it : profit) {
            cout<<it.first<<" "<<it.second<<" "<<it.second-it.first<<endl;
        }
        cout<<endl;
        for(auto it : loss) {
            cout<<it.second<<" "<<it.first<<" "<< it.second-it.first <<endl;
        }
        int ans = INT_MIN;
        int curr = 0;
        for(auto &it : loss) {
            int cost = it.second;
            int cashback = it.first;
            curr += cost;
            ans = max(ans, curr);
            curr -= cashback;
        }
        for(auto &it : profit) {
            int cost = it.first;
            int cashback = it.second;
            curr+= cost;
            ans = max(ans, curr);
            curr -= cashback;
        }
        return ans;

    }
};
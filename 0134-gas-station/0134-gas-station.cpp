class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int diff = INT_MIN;
        vector<int>arr(n);
        int totalCost = 0;
        int totalGas = 0;
        for(int i = 0;i<n;i++) {
            arr[i] = gas[i]- cost[i];
            totalCost += cost[i];
            totalGas += gas[i];
        }
        if(totalCost> totalGas) return -1;
        int idx = 0;
        int tank = 0;
        for(int i = 0 ;i<n ;i++) {
            tank+=arr[i];
            if(tank<0) {
                tank = 0;
                idx = i+1;
            }
        }
        return idx;
    }
};
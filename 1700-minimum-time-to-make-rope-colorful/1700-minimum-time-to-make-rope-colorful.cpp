class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();
        int mini = 0;
        int sum = 0;
        int maxi = 0;
        for(int i = 0;i<n-1;i++) {
            int right = i;
            int left = i;

            if(colors[i] == colors[i+1]) {
                while(left<n-1 && (colors[left] == colors[left+1])) {
                    sum +=neededTime[left];
                    maxi = max(maxi,neededTime[left]);
                    left++;
                }
                sum+=neededTime[left];
                maxi = max(maxi,neededTime[left]);
                mini += sum-maxi;
                i = left;
                sum = 0;
                maxi = 0;
            }
        }
        return mini;
    }
};
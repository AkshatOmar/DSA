class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<int>arrival(n);
        vector<int>dept(n);
        
        for(int i = 0;i<n;i++) {
            arrival[i] = intervals[i][0];
            dept[i] = intervals[i][1];
        }

        sort(dept.begin(),dept.end());
        int cnt = 0;
        int maxCnt = INT_MIN;
        int i = 0, j =0;
        while(i<n) {
            if(arrival[i] <= dept[j]) {
                cnt++;
                i++;
            }
            else {
                cnt--;
                j++;
            }
            maxCnt = max(maxCnt,cnt);
        }
        return maxCnt;
    }
};
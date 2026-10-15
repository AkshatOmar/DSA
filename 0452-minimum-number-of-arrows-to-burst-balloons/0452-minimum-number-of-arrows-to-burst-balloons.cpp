class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(),points.end());
        int cnt = 1;
        int start = points[0][0];
        int end = points[0][1];
        for(int i = 1;i<n;i++) {
            if(points[i][0] <= end) {
                start = min(start,points[i][0]);
                end = min(end,points[i][1]);
            }
            else if(points[i][0] > end) {
                start = points[i][0];
                end = points[i][1];
                cnt++;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int n = apple.size();
        int m = capacity.size();
        sort(capacity.begin(),capacity.end(),greater<int>());
        int totApples = 0;
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            totApples += apple[i];
        }
        for(int i = 0;i<m;i++) {
            totApples -= capacity[i];
            cnt++;
            if(totApples<=0) {
                break;
            }
            
        }
        return cnt;
    }
};
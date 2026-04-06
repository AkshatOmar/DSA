class Solution {
public:
    int hIndex(vector<int>& citations) {
        int cnt = 0;
        int n = citations.size();
        vector<int>count(n+1,0);
        for(int i : citations) {
            if(i>=n) {
                count[n]++;
            }else {
                count[i]++;
            }
        }
        int papers = 0;
        for(int i = n;i>=0;i--) {
            papers+=count[i];
            if(papers >= i) {
                return i;
            }
        }
        return 0;
    }
};
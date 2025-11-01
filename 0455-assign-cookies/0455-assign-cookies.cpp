class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int n1 = g.size();
        int n2 = s.size();
        int l = 0,r = 0,cnt = 0;
        while(l<n1 && r<n2) {
            if(g[l] <=s[r]) {
                cnt++;
                l++;
                r++;
            }
            else if(g[l]>s[r]) r++;
            else l++;
        }
        return cnt;
    }
};
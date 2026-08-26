class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int i =0;
        int j = 0;
        int cnt = 0;
        string ans = "";
        int minLen=INT_MAX;
        while(j<n) {
            if(s[j] == '1') {
                cnt++;
            }
            while(cnt > k) {
                i++;
                cnt--;
            }
            while(cnt == k && s[i] == '0'){
                i++;
            }
            if(cnt == k && minLen == j-i+1) {
                string temp = s.substr(i,j-i+1);
                if(ans > temp) {
                     ans=temp;
                }
                
            }
            if(cnt ==k && minLen > j-i+1) {
                ans = s.substr(i,j-i+1);
                minLen = min(minLen,j-i+1);
            }
            j++;
        }
        return ans;

    }
};
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int i = 0;
        int cnt = 0;
        vector<int>freq(3,0);
        for(int j = 0;j<n;j++) {
            freq[s[j] - 'a']++;
            
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {
                cnt += (n - j);
                freq[s[i]-'a']--;
                i++;
            }
        }
        return cnt;
    }
};
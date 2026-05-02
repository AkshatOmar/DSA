class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        int startidx = -1;

        int minlen = INT_MAX;
        unordered_map<char, int>mp;
        for(int i = 0;i<m;i++) {
            mp[t[i]]++;
        }

        int left = 0;
        int right = 0;
        int cnt = 0;
        while(right < n) {
            if(mp.count(s[right])) {
                if(mp[s[right]] > 0) cnt++;
                mp[s[right]]--;
            }
            
            while(cnt == m) {
                
                if(right-left+1 < minlen) {
                    minlen = right-left+1;
                    startidx = left;
                }
                if(mp.count(s[left])) {
                    mp[s[left]]++;
                    if(mp[s[left]] > 0) {
                        cnt--;
                    }
                }
                left++;
            }
            right++;
        }
        return startidx == -1 ? "" : s.substr(startidx,minlen);
    }
};
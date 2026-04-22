class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        int maxFreq = 0;
        unordered_map<char, int>mp;
        int maxLen = 0;
        int replace = 0;
        while(j<n) {
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);
            replace = j-i+1 - maxFreq;
            //shrink the window;
            while(replace > k) {
                mp[s[i]]--;
                int currMax = INT_MIN;
                for(auto &it : mp) {
                    currMax = max(currMax, it.second);
                }
                //updated maxFrequency.
                maxFreq = currMax;
                i++;
                replace = j-i+1 - maxFreq;
            }
            if(replace <= k) {
                maxLen = max(maxLen, j-i+1);
            }
            j++;
        }
        return maxLen;
    }
};
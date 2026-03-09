class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char,int>mp;
        int maxSize = 0;

        while(j<n) {
            mp[s[j]]++;

            while(mp[s[j]]>1) {
                mp[s[i]]--;
                i++;
            
            }
            maxSize = max(maxSize, j - i + 1);
            j++;
            
        }
        return maxSize;
    }
};
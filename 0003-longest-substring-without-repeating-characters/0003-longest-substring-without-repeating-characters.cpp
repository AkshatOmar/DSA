class Solution {
public:
    bool isRepeating(unordered_map<char,int>&mp) {
        for(auto it : mp) {
            if(it.second > 1) {
                return true;
            }
        }
        return false;
    }
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i = 0, j = 0;
        unordered_map<char,int>mp;
        int maxSize = 0;

        while(j<n) {
            mp[s[j]]++;

            while(isRepeating(mp)) {
                mp[s[i]]--;
                i++;
            
            }
            maxSize = max(maxSize, j - i + 1);
            j++;
            
        }
        return maxSize;
    }
};
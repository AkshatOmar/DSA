class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        if(n != t.size()) return false;
        unordered_map<char,int>mp;
        for(auto it : t) {
            mp[it]++;
        }
        for(auto it : s) {
            if(mp.count(it)) {
                mp[it]--;
            }
            if(mp[it] == 0) {
                mp.erase(it);
            }
        }
        return mp.empty();
    }
};
class Solution {
public:
    bool islower(char it) {
        return (it>='a' && it<='z');
    }
    int numberOfSpecialChars(string word) {
        int n = word.size();
        unordered_map<char, int>mp;
        for(auto it : word) {
            mp[it]++;
        }
        int cnt = 0;
        for(auto it : mp) {
            if(islower(it.first)) {
                char upper = it.first-32;
                if(mp.count(upper)) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
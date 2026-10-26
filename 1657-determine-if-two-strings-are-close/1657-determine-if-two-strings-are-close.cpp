class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<int>w1(26,0),w2(26,0);
        set<char>st1;
        set<char>st2;

        for(char ch : word1) {
            w1[ch-'a']++;
            st1.insert(ch);
        }
        for(char ch : word2) {
            w2[ch-'a']++;
            st2.insert(ch);
        }
        sort(w1.begin(),w1.end());
        sort(w2.begin(),w2.end());
        return w1==w2 && st1== st2;
    }
};
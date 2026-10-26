class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        sort(word1.begin(),word1.end());
        sort(word2.begin(),word2.end());
        if(word1 == word2) return true;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        for(int i = 0;i<n;i++) {
            mp1[word1[i]]++;
        }
        for(int i = 0;i<m;i++) {
            mp2[word2[i]]++;
        }
        string s1 = "";
        string s2 = "";
        string str1 = ""; 
        string str2 = ""; 
        for(auto it : mp1) {
            str1 += it.first;
            s1 += it.second + '0';
        }
        for(auto it : mp2) {
            str2 += it.first;
            s2 += it.second + '0';
        }
        sort(s1.begin(),s1.end());
        sort(s2.begin(),s2.end());
        
        return (s1==s2) && (str1 == str2);
    }
};
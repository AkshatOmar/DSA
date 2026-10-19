class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i'||ch == 'o'||ch == 'u'||ch == 'A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U');
    }
    string reverseVowels(string s) {
        int n = s.size();
        string temp = "";
        for(int i = 0;i<n;i++) {
            if(isVowel(s[i])) {
                temp += s[i];
            }
        }

        int j = temp.size()-1;
        for(int i = 0;i<n;i++) {
            if(isVowel(s[i])) {
                s[i] = temp[j];
                j--;
            }
        }
        return s;
    }
};
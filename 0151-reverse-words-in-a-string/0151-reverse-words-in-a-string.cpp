class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string>str;
        string temp = "";
        for(int i =0;i<n;i++) {
            if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >='0' && s[i] <='9')) {
                temp += s[i];
            }
            
            if(s[i] == ' ' && temp != "") {
                str.push_back(temp);
                temp = "";
            }
        }
        if(temp != "") {
            str.push_back(temp);
        }
        string ans="";
        for(int i = str.size()-1;i>=0;i--) {
            ans += str[i];
            if(i!=0) ans +=' ';
        }
        return ans;
    }
};
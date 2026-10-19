class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        reverse(s.begin(),s.end());
        int start = 0;
        int end = 0;
        int i = 0;
        string ans="";
        while(i<n) {
            
            while(i<n && s[i] == ' ') {
                i++;
                start++;
                end++;
            }
            if(i==n) break;
            
            while(i<n && s[i] != ' ') {
                end++;
                i++;
            }
            string temp = s.substr(start,end-start);
            reverse(temp.begin(),temp.end());
            ans += temp;
            ans += ' ';
            i = end;
            start = end;
        }
        ans.resize(ans.size()-1);
        return ans;
    }
};
class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string res="";
        for(int i = 0;i<n;i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                res += s[i];
            }
            else if(s[i] == '*' && !res.empty()) {
                res.pop_back();
            }
            else if(s[i] == '#' && !res.empty()) {
                string temp = res;
                for(auto c : temp) {
                    res += c;
                }
            }
            else if(s[i] == '%' && !res.empty()) {
                reverse(res.begin(),res.end());
            }
        }
        return res;
    }
};
class Solution {
public:
    string helper(string &s, int &i) {
        int num = 0;
        string ans = "";
        while(i<s.size()) {
            if(s[i] >='0' && s[i] <= '9') {
                num = num * 10 + (s[i]-'0');
                i++;
            }
            else if(s[i] == '[') {
                i++;
                string temp = helper(s,i);
                for(int j = 0;j<num;j++) {
                    ans += temp;
                }
                num = 0;
            }
            else if(s[i]==']') {
                i++;
                return ans;
            }
            else {
                ans += s[i];
                i++;
            }
        }
        return ans;
    }
    string decodeString(string s) {
        int n = s.size();
       
        int i = 0;
        return helper(s,i);
        
    }
};
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int>st;
        int n = s.size();
        string ans;
        for(int i = 0;i<n;i++) {
            if(s[i] == '(') {
                st.push(ans.size());
            }
            else if(s[i] == ')') {
                int start = st.top();
                st.pop();
                reverse(ans.begin()+start,ans.end());
            }
            else {
                ans += s[i];
            }
        }
        return ans;
    }
};
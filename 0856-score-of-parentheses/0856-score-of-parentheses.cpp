class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int>st;
        st.push(0);
        for(int i = 0;i<n;i++) {
            if(s[i] == '(') {
                st.push(0);
            }
            else {
                int inner = st.top();
                st.pop();
                int val = max(2*inner,1);
                st.top() += val;
            }
        }
        return st.top();
    }
};
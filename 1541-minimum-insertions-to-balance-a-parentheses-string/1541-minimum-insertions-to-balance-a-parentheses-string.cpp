class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        stack<char>st;
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            if(s[i] == '(') {
                st.push(s[i]);
            }
            else if(s[i] == ')') {
                if(!st.empty() && s[i+1] == ')') {
                    st.pop();
                    i++;
                }
                else if(st.empty() && s[i+1] == ')') {
                    cnt++;
                    i++;
                }
                else if(st.empty() && s[i+1] != ')') {
                    cnt+=2;
                }
                else if(!st.empty() && s[i+1]!=')') {
                    st.pop();
                    cnt++;
                }
                

            }
        }
        if(!st.empty()) {
            cnt += 2*st.size();
        }
        return cnt;
    }
};
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
                if(!st.empty()) {
                    if(s[i+1] == ')') {
                        st.pop();
                        i++;
                        
                    }
                    else {
                        st.pop();
                        cnt++;
                    }
                }
                else {
                    if(s[i+1] == ')') {
                        cnt++;
                        i++;
                    }
                    else {
                        cnt+=2;
                    }
                }
            }
        }
        if(!st.empty()) {
            cnt += 2*st.size();
        }
        return cnt;
    }
};
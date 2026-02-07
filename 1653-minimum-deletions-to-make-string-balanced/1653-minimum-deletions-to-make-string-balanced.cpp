class Solution {
public:
    int minimumDeletions(string s) {
        stack<char>st;
        int del = 0;
        int n = s.size();
        int i=0;
        while(i<n) {
            if(!st.empty() && st.top() =='b' && s[i] == 'a') {
                st.pop();
                del++;
            }
            else st.push(s[i]);
            i++;
        }
        return del;
    }
};
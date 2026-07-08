class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        stack<int>st;
        int i = 0;
        int unbalanced = 0;
        while(i<n) {
            if(s[i] == '[') {
                st.push(s[i]);
            }
            else if(s[i] == ']') {
                if(!st.empty()) {
                    st.pop();
                }
                else unbalanced++;

            }
            i++;
        }
        return (unbalanced+1)/2;
    }
};
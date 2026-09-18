class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char>st;
        string ans ="";
        int cnt = k;
        
        for(int i = 0;i<n;i++) {
            
            while(cnt>0 && !st.empty() && st.top() > num[i]) {
                st.pop();
                cnt--;
            }
            st.push(num[i]);
        }
        while(cnt>0) {
            st.pop();
            cnt--;
        }
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        int i =0;
        

        reverse(ans.begin(),ans.end());
        while(i<ans.size() && ans[i] == '0'){
            i++;
        }
        ans = ans.substr(i);
        return ans.empty() ? "0":ans;
    }
};
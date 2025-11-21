class Solution {
public:
    int countPalindromicSubsequence(string s) {
        // initialize 2 array for storing the occurance of each character
        int n = s.size();
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        for(int i = 0;i<n;i++) {
            int c = s[i]-'a';
            if(first[c] == -1) {
                first[c] = i;
            }else {
                last[c] = i;
            }
        }
        int ans = 0;
        for(int i = 0;i<26;i++) {
            if(last[i]-first[i] >= 2) {
                unordered_set<int>st;
                for(int j = first[i]+1;j<=last[i]-1;j++) {
                    st.insert(s[j]);
                }
                ans+= st.size();
            }
        }
        return ans;
    }
};
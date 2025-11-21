class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.size();
        vector<int>firstOcc(26,-1);
        vector<int>lastOcc(26,-1);
        for(int i = 0;i<n;i++) {
            int c = s[i]-'a';
            if(firstOcc[c]== -1) {
                firstOcc[c] = i;
            }
            else{
                lastOcc[c] = i;
            }
        }
        int ans = 0;
        for(int i = 0;i<26;i++) {
            if(lastOcc[i]-firstOcc[i] >= 2){
                unordered_set<int>st;
                for(int j = firstOcc[i]+1; j<=lastOcc[i]-1; j++) {
                    st.insert(s[j]);
                }
                ans += st.size();
            }
        }
        return ans;
    }
};
class Solution {
public:

    int n;
    unordered_set<string>st;
    int t[301];
    bool solve(int idx, string&s) {
        if(idx == n) {
            return true;
        }
        if(t[idx]!=-1) 
            return t[idx];
        if(st.find(s)!=st.end())
            return true;
        for(int i = 1;i<n;i++) {
            string temp = s.substr(idx, i);
            if(st.find(temp) != st.end()&& solve(idx+i, s)) 
                return true;
        }
        return t[idx] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        memset(t,-1,sizeof(t));
        for(string &word : wordDict) {
            st.insert(word);
            
        }
        return solve(0,s);
    }
};
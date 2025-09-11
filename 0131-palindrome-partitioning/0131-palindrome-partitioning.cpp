class Solution {
public:
    bool ispallindrome(string s, int i, int idx) {
        while(idx<i) {
            if(s[idx]!=s[i]) {
                return false;
                
            }
            idx++;
            i--;
        }
        return true;
    }
    void helper(vector<vector<string>>&res, string s, vector<string>&temp, int idx) {
        if(idx== s.size()) {
            res.push_back(temp);
            return;
        }
        for(int i = idx;i<s.size();i++) {
            if(ispallindrome(s,i,idx)){
                temp.push_back(s.substr(idx,i-idx+1));
                helper(res,s,temp,i+1);
                temp.pop_back();
            }
            
        }
        
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string> temp;
        helper(res,s, temp, 0);
        return res;
    }
};
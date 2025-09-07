class Solution {
public:
    void helper(int n,vector<string>&res,string curr, int open, int close){
        if(curr.size() == n*2) {
            res.push_back(curr);
            return;
        }
        if(open<n) {
            helper(n, res, curr+"(",open+1, close);
        }
        if(close<open) {
            helper(n, res, curr+")",open, close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>res;
        helper(n, res, "", 0,0);
        return res;
    }
};
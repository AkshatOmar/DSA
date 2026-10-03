class Solution {
public:
    void helper(vector<string>&ans, string temp, int n, int i, int open, int close) {
        if(i == 2*n) {
            ans.push_back(temp);
            return;
        }
        if(open<n) {
            helper(ans,temp+'(',n,i+1,open+1,close);
        }
        if(open>close) {
            helper(ans,temp+')',n,i+1,open,close+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        helper(ans,"",n,0,0,0);
        return ans;
    }
};
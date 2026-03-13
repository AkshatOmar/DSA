class Solution {
public:
    void generate(vector<string>&ans, string temp, int n, int open,int close,int i) {
        if(i == n*2) {
            ans.push_back(temp);
            return;
        }
        if(open < n) {
            temp +='(';
            generate(ans,temp,n,open+1,close,i+1);
            temp.pop_back();
        }
        if(close < open){
            temp +=')';
            generate(ans,temp,n,open,close+1,i+1);
            temp.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        generate(ans, "", n, 0,0,0);
        return ans;
    }
};
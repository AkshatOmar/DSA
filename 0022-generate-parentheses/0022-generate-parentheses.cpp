class Solution {
public:
    void helper(vector<string>&ans, string temp, int i, int n,int cnt) {
        if(i == 2*n) {
            if(cnt==0){
                ans.push_back(temp);
            }
            return;
        }
        
        if(i+cnt < 2*n) {
            
           // cnt++;
             helper(ans,temp+'(',i+1,n,cnt+1);
        }
        if(cnt>0) {
            //cnt--;
            helper(ans,temp+')',i+1,n,cnt-1);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        // int cnt = 0;
        helper(ans,"",0,n,0);
        return ans;
    }
};
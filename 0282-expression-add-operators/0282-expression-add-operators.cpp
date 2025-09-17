class Solution {
public:
    int n;
    void solve(vector<string>&res,string num, int target,string curr, int idx, long long total,long long lastNum){
        if(idx == n&&total == target){
            res.push_back(curr);
            return;
        }
        for(int i = idx;i<n;i++) {
            string part = num.substr(idx, i-idx+1);
            long long currNum = stoll(part);
            if(part.size()>1&&part[0] == '0') break;
            if(idx == 0) {
                solve(res, num, target, part,i+1,currNum,currNum);
            }
            else{
                solve(res,num,target,curr+'+'+part,i+1,total+currNum,currNum);
                solve(res,num,target,curr+'-'+part,i+1,total-currNum,-currNum);
                solve(res,num,target,curr+'*'+part,i+1,total-lastNum+lastNum*currNum,lastNum*currNum);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        n = num.size();
        vector<string>res;
        solve(res,num,target,"",0,0,0);
        return res;
    }
};
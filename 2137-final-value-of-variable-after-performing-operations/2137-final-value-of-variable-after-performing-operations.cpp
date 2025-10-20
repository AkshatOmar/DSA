class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int cnt = 0;
        for(string operation : operations) {
            if(operation == "X++"||operation == "++X"){
                cnt++;
            }
            else {
                cnt--;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    bool judgeCircle(string moves) {
        int n = moves.size();
        int cnt = 0;
        for(int  i = 0;i<n;i++) {
            if(moves[i] == 'L' || moves[i] == 'U') {
                cnt++;
            }
            else if(moves[i] == 'R' || moves[i] == 'D') {
                cnt--;
            }
        }
        return (cnt == 0) ? true : false;
    }
};
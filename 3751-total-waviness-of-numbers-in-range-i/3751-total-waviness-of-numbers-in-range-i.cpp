class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int cnt = 0;
        for(int i = num1;i<=num2;i++) {
            string n1 = to_string(i);
            for(int j = 1;j<n1.size()-1;j++) {
                if(n1[j] - '0'>n1[j-1]-'0' && n1[j]-'0'>n1[j+1]-'0') {
                    cnt++;
                }
                else if(n1[j]-'0'<n1[j-1]-'0' && n1[j]-'0'<n1[j+1]-'0') {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
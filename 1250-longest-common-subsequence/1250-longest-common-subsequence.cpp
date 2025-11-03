class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size();
        int n2 = text2.size();
        vector<int>prev(n2+1,0);
        vector<int>curr(n2+1,0);
        for(int i1 = 1;i1<=n1;i1++) {
            for(int i2 = 1;i2<=n2;i2++) {
                if(text1[i1-1] == text2[i2-1]) {
                    curr[i2] = 1+prev[i2-1];
                }
                else {
                    curr[i2] = max(prev[i2],curr[i2-1]);
                }
            }
            prev = curr;
        }
        return prev[n2];
    }
};
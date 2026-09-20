class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int degree = 0;
        for(int i = 0;i<n;i++) {
            degree+= ('z'-s[i] + 1)* (i+1);
        }
        return degree;
    }
};
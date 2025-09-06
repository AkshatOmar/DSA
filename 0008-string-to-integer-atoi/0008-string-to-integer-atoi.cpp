class Solution {
public:
    int helper(string &s, int index, int sign, long numSoFar) {
        if(index>= s.size() || !isdigit(s[index])) {
            return numSoFar;
        }
        int digit = s[index] - '0';
        long newNum = numSoFar*10 + digit;
        if(sign == 1 && newNum>INT_MAX) return INT_MAX;
        if(sign == -1 && -newNum<INT_MIN) return INT_MIN;
        return helper(s,index+1, sign, newNum);
    }
    int myAtoi(string s) {
        int num = 0,i =0,sign = 1;
        while(i<s.size() && s[i] == ' ') i++;
        if(i< s.size() && (s[i] == '+' || s[i] == '-')){
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        long result = helper(s,i,sign, num);
        return(int)(sign*result) ;
    }
};
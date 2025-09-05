class Solution {
public:
    int myAtoi(string s) {
        long num = 0;
        int i = 0, n = s.size();
        int sign = 1;
        while (i < n && s[i] == ' ') i++;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }
        while (i < n && isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
            if (sign == 1 && num > INT_MAX) return INT_MAX;
            if (sign == -1 && -num < INT_MIN) return INT_MIN;

            i++;
        }

        return (int)(sign * num);
    }
};

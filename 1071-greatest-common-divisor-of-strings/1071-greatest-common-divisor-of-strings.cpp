class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int n = str1.size();
        if(str1+str2 != str2+str1) {
            return "";
        }
        int len =  gcd(str1.size(),str2.size());
        return str1.substr(0,len);
    }
};
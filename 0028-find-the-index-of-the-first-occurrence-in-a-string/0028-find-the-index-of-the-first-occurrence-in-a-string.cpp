class Solution {
    private:
    vector<int> computeLPSArray(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0);
    int length = 0;
    int i = 1;

    while (i < m) {
        if (pattern[i] == pattern[length]) {
            length++;
            lps[i] = length;
            i++;
        } else {
            if (length != 0) {
                length = lps[length - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
    return lps;
}

public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m = needle.length();

        if (m == 0) return 0; 
        if (m > n) return -1; 

        vector<int> lps = computeLPSArray(needle);
        int i = 0, j = 0;

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }
            if (j == m) {
                return i - j; 
            } else if (i < n && haystack[i] != needle[j]) {
                if (j != 0) {
                    j = lps[j - 1];
                } else {
                    i++;
                }
            }
        }
        return -1; 

    }
};
class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        if(n != m) return false;
        string doubleString = s+s;
        int i = 0, j = n-1;
        while(j<n+n) {
            if(doubleString.substr(i,j-i+1) == goal) return true;
            i++;
            j++;
        }
        return false;
    }
};
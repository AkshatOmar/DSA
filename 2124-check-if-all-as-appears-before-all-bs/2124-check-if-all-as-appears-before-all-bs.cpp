class Solution {
public:
    bool checkString(string s) {
        bool flag = false;
        int n = s.size();
        
        for(int i = 0;i<n;i++) {
            if(s[i] == 'b') {
                flag = true;
            }
            if(flag) {
                if(s[i] == 'a') return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int zeros = 0;
        for(int i = 0;i<n;i++) {
            if(i%2 == 0) {
                if(s[i] == '1') zeros++;
                
            }else {
                if(s[i] == '0') zeros++;
            }
            
        }
        
        return min(zeros,n-zeros);
    }
};
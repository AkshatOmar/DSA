class Solution {
public:
    bool isVowel(char ch){
        return(ch=='a' || ch == 'e'||ch == 'i'||ch == 'o'||ch == 'u'||ch == 'A'||ch == 'E'||ch == 'I'||ch == 'O'||ch == 'U');
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int i = 0;
        int j = 0;
        int cnt = 0;
        int ans=0;
        while(j<n) {
            if(isVowel(s[j])) {
                cnt++;
            }
            if(k==j-i+1){
                ans=max(cnt,ans);
                if(isVowel(s[i])){
                    cnt--;
                    
                }
                i++;
            }
            j++;
        }
        return ans;
    }
};
class Solution {
public:
    
    int maxNumberOfBalloons(string text) {
        int size  = text.size();
        int b = 0, a = 0, l = 0, o = 0, n = 0;
        for(int i = 0;i<size;i++) {
            if(text[i] == 'b') b++;
            if(text[i] == 'a') a++;
            if(text[i] == 'l') l++;
            if(text[i] == 'o') o++;
            if(text[i] == 'n') n++;
        }
        return min({b,a,l/2,o/2,n});

    }
};
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size();
        int len = INT_MAX;

        for(int i = startIndex;i<n;i++) {
            if(words[i] == target) {
                len = min({len, i-startIndex,(n-(i-startIndex))});
            }
        }
        for(int i = startIndex;i>=0;i--) {
            if(words[i] == target) {
                len = min({len, startIndex-i,(n-(startIndex-i))});
                
            }
        }
        return len == INT_MAX ? -1 : len;
    }
};
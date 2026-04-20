class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i = 0, j = 0;
        unordered_map<int,int>mp;
        int maxlen = INT_MIN;

        while(j<n) {
            mp[fruits[j]]++;
            
            while(mp.size() > 2) {
                mp[fruits[i]]--;
                if(mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            j++;
            maxlen = max(maxlen,j-i);
        }
        return maxlen;
    }
};
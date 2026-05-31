class Solution {
public:
    int digitFrequencyScore(int n) {
        unordered_map<int,int>mp;
        int num = n;
        while(num>0) {
            int digit = num%10;
            mp[digit]++;
            num = num/10;
        }
        int score = 0;
        for(auto it : mp) {
            score += it.first * it.second;
        }
        return score;
    }
};
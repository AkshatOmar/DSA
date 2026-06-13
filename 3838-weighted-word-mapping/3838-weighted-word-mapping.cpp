class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans="";
        for(string &word : words) {
            int sum = 0;
            for(int i = 0;i<word.size();i++) {
                sum+=weights[word[i]-'a'];
            }
            sum = sum%26;
            char c = 'z'-sum;
            ans += c;
        }
        return ans;
    }
};
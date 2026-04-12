class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string, int>mp;
        vector<string>ans;

        for(int i = 0;i+9<n;i++) {
            string temp = s.substr(i,10);
            mp[temp]++;
            if(mp[temp] == 2) {
                ans.push_back(temp);
            }
        }
        
        return ans;
    }
};
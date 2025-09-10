class Solution {
public:
    void helper(vector<string>&res, string&digits,unordered_map<char, string>&mp, string temp, int idx) {
        if(idx >= digits.size()) {
            res.push_back(temp);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for(int i = 0;i<str.size();i++) {
            temp.push_back(str[i]);
            helper(res, digits,mp, temp,idx+1);
            temp.pop_back();
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.size() == 0) {
            return {};
        }
        unordered_map<char, string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        helper(res, digits,mp, "", 0);
        return res;
    }
};
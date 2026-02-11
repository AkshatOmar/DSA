class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int v = wordList.size();
        //using set for O(1) lookup
        unordered_set<string>st;
        for(auto &word : wordList) {
            st.insert(word);
        }
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()) {
            string s = q.front().first;
            int step = q.front().second;
            q.pop();
            st.erase(s);
            if(s == endWord) {
                return step;
            }
            for(int i =0;i<s.size();i++) {
                char word = s[i];
                for(char ch = 'a';ch<='z';ch++) {
                    s[i] = ch;
                    if(st.find(s) != st.end()) {
                        cout<<s<<endl;
                        st.erase(s);
                        q.push({s,step+1});
                    }
                }
                s[i] = word;
            }
        }
        return 0;
    } 
};
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st;
        for(string s : wordList) {
            st.insert(s);
        }
        //make a queue and store string and steps
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        while(!q.empty()) { 
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            st.erase(word);
            for(int i = 0;i<word.size();i++) {
                char og = word[i];
                for(char ch = 'a';ch<='z';ch++) {
                    word[i] = ch;
                    if(st.find(word) != st.end()) {
                        q.push({word,steps+1});
                    }
                }
                //cout<<word<<endl;
                word[i]=og;
            }
        }
        return 0;
    }
};
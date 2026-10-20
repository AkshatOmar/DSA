class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();

        int i = 0, j = 0; 
        int k = 0;

        while(j<n) { 
            int currLen = 0;
            while(j<n && chars[i] == chars[j]) {
                j++; 
                currLen++; 
            }
            
            chars[k] = chars[i];
            k++;
            
            if(currLen>1) {
                string temp = to_string(currLen);
                int itr = 0;
                while(itr<temp.size()) {
                    chars[k] = temp[itr];
                    k++;
                    itr++;
                }
                
            }
            i = j;
        }
        return k;
    }
};
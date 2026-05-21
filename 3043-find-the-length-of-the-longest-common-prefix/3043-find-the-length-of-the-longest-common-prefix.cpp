class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        unordered_set<int>st;
        for(auto it : arr1) {
            while(!st.count(it) && it > 0) {
                st.insert(it);
                it = it/10;
            }
        }
        int maxPref = 0;
        for(int it : arr2) {
            while(!st.count(it) && it > 0) {
                it /= 10;
            }
            if(it > 0) {
                maxPref = max(maxPref,static_cast<int>(log10(it) + 1));
            }
        }
        return maxPref;
    }
};
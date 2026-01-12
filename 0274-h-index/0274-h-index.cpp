class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end(),greater<int>());
        int n=citations.size();
        int index=0;
        while(index<n&&citations[index]>index){
            index+=1;
        }
        return index;
    }
};
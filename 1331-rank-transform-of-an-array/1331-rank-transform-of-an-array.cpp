class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        map<int,int>mp;
        vector<int>sorted(arr);
        //sorted the array
        sort(sorted.begin(),sorted.end());
        int rnk = 1;
        //associated rank with array using map
        for(int i = 0;i<n;i++) {
            if(i>0 && sorted[i] > sorted[i-1]){
                rnk++;
            }
            mp[sorted[i]] = rnk;
        }
        // retrived rank from map
        for(int i = 0;i<n;i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;


    }
};
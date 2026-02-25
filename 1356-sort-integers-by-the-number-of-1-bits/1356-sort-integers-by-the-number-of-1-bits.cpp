class Solution {
public:
    int countSetBits(int num) {
        int cnt=0;
        while(num>0) {
            if(num%2==1)cnt++;
            num = num/2;
        }
        return cnt;
    }
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>>bitspair;
        for(int i =0;i<n;i++) {
            int setBits = countSetBits(arr[i]);
            bitspair.push_back({setBits,arr[i]});
        }
        sort(bitspair.begin(),bitspair.end());
        vector<int>ans;
        for(auto it : bitspair) {
            ans.push_back(it.second);
        }
        return ans;
    }
};
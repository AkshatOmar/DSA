class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        
        int n = arr1.size();
        int m = arr2.size();
        int cnt = 0;
        for(auto &it : arr1) {
            bool flag=true;
            for(auto &it2 : arr2) {
                flag &= (abs(it-it2) > d);
            }
            cnt+=flag;
        }
        return cnt;
    }
};
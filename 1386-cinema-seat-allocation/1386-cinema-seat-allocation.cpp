class Solution {
public:
    bool isAvailable(unordered_map<int,unordered_set<int>>&mp, int it,int val) {
        return mp[it].find(val) == mp[it].end();
    }
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mp;
        int res = 0;
        for(auto it : reservedSeats) {
            mp[it[0]].insert(it[1]);
        }
        res += (n - mp.size())*2;
        for(auto it : mp) {
            bool groupA = isAvailable(mp,it.first,2) && isAvailable(mp,it.first,3) && isAvailable(mp,it.first,4) && isAvailable(mp,it.first,5);
            bool groupB = isAvailable(mp,it.first,4) && isAvailable(mp,it.first,5) && isAvailable(mp,it.first,6) && isAvailable(mp,it.first,7);
            bool groupC = isAvailable(mp,it.first,6) && isAvailable(mp,it.first,7) && isAvailable(mp,it.first,8) && isAvailable(mp,it.first,9);

            if(groupA && groupC) {
                res += 2;
            }
            else if(groupA || groupB || groupC) {
                res += 1;
            }
        }
        return res;

    }
};
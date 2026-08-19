class Solution {
public:
    
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,unordered_set<int>>mp;
        int res = 0;
        for(auto& it : reservedSeats) {
            mp[it[0]].insert(it[1]);
        }
        res += (n - mp.size())*2;
        for(auto& [row, bookedSeats] : mp) {
            auto isAvailable = [&](int seat) {
                return bookedSeats.find(seat) == bookedSeats.end();
            };
            bool groupA = isAvailable(2) && isAvailable(3) && isAvailable(4) && isAvailable(5);
            bool groupB = isAvailable(4) && isAvailable(5) && isAvailable(6) && isAvailable(7);
            bool groupC = isAvailable(6) && isAvailable(7) && isAvailable(8) && isAvailable(9);

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
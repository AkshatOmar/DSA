class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysBeforeMonth = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        
        int arriveAliceDay = calculateDayOfYear(arriveAlice, daysBeforeMonth);
        int leaveAliceDay = calculateDayOfYear(leaveAlice, daysBeforeMonth);
        int arriveBobDay = calculateDayOfYear(arriveBob, daysBeforeMonth);
        int leaveBobDay = calculateDayOfYear(leaveBob, daysBeforeMonth);
        
        int overlapStart = max(arriveAliceDay, arriveBobDay);
        int overlapEnd = min(leaveAliceDay, leaveBobDay);
        
        return max(0, overlapEnd - overlapStart + 1);
    }
    
    int calculateDayOfYear(const string& dateStr, const vector<int>& daysBeforeMonth) {
        int month = stoi(dateStr.substr(0, 2));
        int day = stoi(dateStr.substr(3, 2));
        return daysBeforeMonth[month - 1] + day;
    }
};
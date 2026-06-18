class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes*6.0;
        double hourAngle = 30.0 * (hour%12) + 0.5 * minutes;
        double diff = abs(minuteAngle- hourAngle);
        return min(diff,360.0-diff);
    }
};
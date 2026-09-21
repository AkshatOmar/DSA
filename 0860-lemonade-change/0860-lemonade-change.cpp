class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        vector<int>notes(2,0);
        for(int i = 0;i<n;i++) {
            if(bills[i] == 5) {
                notes[0]++;
            }
            else if(bills[i] == 10) {
                if(notes[0] > 0) {
                    notes[0]--;
                    notes[1]++;
                }
                else {
                    return false;
                }
            }
            else {
                if(notes[1]>0 && notes[0]>0) {
                    notes[1]--;
                    notes[0]--;
                    
                }
                else if(notes[0] >= 3) {
                    notes[0] -= 3;
                    
                }
                else {
                    return false;
                }
            }
        }
        return true;
    }
};
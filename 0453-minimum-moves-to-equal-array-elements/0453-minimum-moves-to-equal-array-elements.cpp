class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n =  nums.size();
        int mini = -1;
        int minNum = INT_MAX;
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            minNum = min(minNum, nums[i]);
        }
        for(int i = 0;i<n;i++) {
            cnt += nums[i] - minNum;
        }
        return cnt;
    }
};
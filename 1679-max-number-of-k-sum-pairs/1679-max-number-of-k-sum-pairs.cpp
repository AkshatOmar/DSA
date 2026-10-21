class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0,j = n-1;
        int cnt = 0;
        int sum = 0;
        while(i<j) {
            sum = nums[i]+nums[j];
            if(sum>k) {
                j--;
            }
            else if(sum<k) {
                i++;
            }
            else {
                i++;
                j--;
                cnt++;
            }
        }
        return cnt;
    }
};
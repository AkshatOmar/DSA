class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n);
        for(int i = 0;i<n;i++) {
            int idx = 0;
            for(int j = i;j<n;j++) {
                arr[idx] = nums[j];
                idx++;
            }
            for(int k = 0;k<i;k++) {
                arr[idx++] = nums[k];
            }
            bool isSorted = true;
            for(int j = 0;j<n-1;j++) {
                if(arr[j] > arr[j+1]){
                    isSorted = false;
                    break;
                }
            }
            if(isSorted) return true;
        }
        return false;
    }
};
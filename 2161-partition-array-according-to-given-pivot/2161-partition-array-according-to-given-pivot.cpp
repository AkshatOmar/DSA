class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int>arr1;
        vector<int>arr2;
        int cnt = 0;
        for(int i = 0;i<n;i++) {
            if(nums[i] == pivot) {
                cnt++;
            }
            else if(nums[i] < pivot) {
                arr1.push_back(nums[i]);
            }
            else{
                arr2.push_back(nums[i]);
            }
        }

        vector<int>ans;
        for(int i = 0;i<arr1.size();i++) {
            ans.push_back(arr1[i]);
        }
        while(cnt--) {
            ans.push_back(pivot);
        }
        for(int i = 0;i<arr2.size();i++) {
            ans.push_back(arr2[i]);
        }
        return ans;
    }
};
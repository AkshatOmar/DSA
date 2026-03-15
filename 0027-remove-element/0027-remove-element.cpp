class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i  = 0, j = n-1;
        int cnt = n;
        for(int i = 0;i<n;i++) {
            if(nums[i] == val) cnt--;
        }
        while(i<j) {
            if(nums[i] == val && nums[j] != val) {
                swap(nums[i],nums[j]);
                i++;
                j--;
                
            }
            else if(nums[j] == val && nums[i] == val) {
                j--;
                
            }
            else if(nums[j] == val && nums[i]!= val) {
                j--;
                
            }
            else if(nums[i] != val && nums[j] != val) {
                i++;
                
            }
            else {
                i++;
            }
        }
        return cnt;
    }
};
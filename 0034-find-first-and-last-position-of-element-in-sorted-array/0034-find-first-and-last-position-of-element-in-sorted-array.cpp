class Solution {
public:
    int firstOcc(vector<int>&nums,int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int first = -1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(nums[mid] == target) {
                high = mid-1;
                first = mid;
            }
            else if(nums[mid] < target) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return first;
    }
    int lastOcc(vector<int>&nums,int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int last = -1;
        while(low<=high) {
            int mid = low+(high-low)/2;
            if(nums[mid] == target) {
                low = mid+1;
                last = mid;
            }
            else if(nums[mid] < target) {
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstOcc(nums,target);
        if(first == -1) return {-1,-1};
        return {first,lastOcc(nums,target)};
    }
};
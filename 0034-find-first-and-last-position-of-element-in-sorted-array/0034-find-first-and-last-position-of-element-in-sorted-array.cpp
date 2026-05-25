class Solution {
public:
    int lowerBound(vector<int>&nums, int target) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        int lb = n;
        while(i<=j) {
            int mid = i + (j-i)/2;
            if(nums[mid] >= target) {
                lb = mid;
                j = mid-1;
            }
            else {
                i = mid+1;
            }
        }
        return lb;
    }
    int upperBound(vector<int>&nums,int target) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        int ub = n;
        while(low<=high) {
            int mid = low + (high-low)/2;
            if(nums[mid] > target) {
                ub = mid;
                high = mid-1;
            }
            else {
                low = mid+1;
            }
        }
        return ub;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums,target);
        
        if(lb == n || nums[lb] != target) return {-1,-1};
        return {lb,upperBound(nums,target)-1};
    }
};
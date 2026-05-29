class Solution {
public:
    int minElement(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n);
        for(int i = 0;i<n;i++) {
            int sum = 0;
            int num = nums[i];
            while(num>0) {
                int digit = num%10;
                sum += digit;
                num = num/10;
            }
            arr[i] = sum;
        }
        
        int ans =  INT_MAX;
        for(int i = 0;i<n;i++) {
            cout<<arr[i]<<endl;
            ans = min(ans,arr[i]);
        }
        return ans;
    }
};
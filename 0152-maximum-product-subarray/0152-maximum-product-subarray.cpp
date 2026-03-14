class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxProd = INT_MIN;
        int prod = 1;
        
        for(int i = 0;i<n;i++) {
            prod = nums[i]*prod;
            maxProd = max(prod,maxProd);
            if(prod == 0) {
                prod = 1;
            }
            
        }
        int maxLeft = INT_MIN;
        int leftProd = 1;
        for(int i = n-1;i>=0;i--) {
            leftProd = nums[i]*leftProd;
            maxLeft = max(leftProd,maxLeft);
            if(leftProd == 0) {
                leftProd = 1;
            }
           
        }
        return max(maxProd, maxLeft);
    }
};
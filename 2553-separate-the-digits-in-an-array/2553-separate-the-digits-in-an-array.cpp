class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i = 0;i<n;i++) {
            vector<int>temp;
            int num = nums[i];
            while(num > 0) {
                temp.push_back(num % 10);
                num /= 10;
            }
            reverse(temp.begin(),temp.end());
            for(int &it : temp) {
                ans.push_back(it);
            }
        }
        return ans;
    }
};
class Solution {
public:
    void findNSE(vector<int>&arr,vector<int>&nse, int n) {
        stack<int>st;

        for(int i =n-1;i>=0;i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = !st.empty() ? (st.top()-i) : (n-i);
            st.push(i);
        }
    }
    void findPSE(vector<int>&arr,vector<int>&pse, int n) {
        stack<int>st;
        for(int i =0 ;i<n;i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();

            }
            pse[i] = !st.empty() ? i-st.top() : (i+1);
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        int mod = 1e9+7;
        vector<int>pse(n);
        vector<int>nse(n);
        findNSE(arr,nse,n);
        findPSE(arr,pse,n);
        
        for(int i = 0;i<n;i++) {
            long long cnt = (1LL*nse[i]*pse[i])%mod;
            sum = (sum+cnt*arr[i])%mod;
        }
        return sum;
    }
};
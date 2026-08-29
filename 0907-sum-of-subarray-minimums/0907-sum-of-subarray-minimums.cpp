class Solution {
public:
    void findNSE(vector<int>&arr, vector<int>&nse) {
        int n =arr.size();
        stack<int>st;
        for(int i = n-1;i>=0;i--) {
           
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n:st.top();
            st.push(i);
        }
    
    }
    void findPSE(vector<int>&arr, vector<int>&pse) {
        int n = arr.size();
        stack<int>st;
        for(int i = 0;i<n;i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        long long mod = (int)1e9+7;
        long long sum = 0;
        vector<int>nse(n);
        vector<int>pse(n);
        findNSE(arr,nse);
        findPSE(arr,pse);
        
        for(int i = 0;i<n;i++) {
            int left = i-pse[i];
            int right=nse[i]-i;
            sum = (sum+((right*left)%mod*arr[i])%mod)%mod;
        }
        return sum;
    }
};
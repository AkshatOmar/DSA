class Solution {
public:
    int calcArea(vector<int>arr) {
        stack<int>st;
        int n = arr.size();
        int idx = 0;
        int nse = n,pse = -1;
        int area = 0;
        for(int i = 0;i<n;i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                idx = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                area = max(area, arr[idx]* (nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()) {
            idx = st.top();
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();
            area = max(area,arr[idx]*(nse-pse-1));
        }
        return area;
    }   
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>>pref(n,vector<int>(m,0));

        for(int i = 0;i<m;i++) {
            int sum = 0;
            for(int j = 0;j<n;j++) {
                if(matrix[j][i] == '1') sum += 1;
                if(matrix[j][i] == '0') sum = 0;
                pref[j][i] = sum;
            }
        }
        int area = 0;
        for(int i = 0;i<n;i++) {
            area = max(area,calcArea(pref[i]));
        }
        return area;
    }
};
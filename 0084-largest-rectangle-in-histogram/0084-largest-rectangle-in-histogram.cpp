class Solution {
public:
    void findNSE(vector<int>&heights, vector<int>&nse, int n) {
        stack<int>st;
        for(int i = n-1;i>=0;i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

    }
    void findPSE(vector<int>&heights, vector<int>&pse, int n) {
        stack<int>st;
        for(int i = 0;i<n;i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        // intution -> find Minimum of the subarray and then find the max area;
        int n = heights.size();
        int area = 0;
        vector<int>pse(n);
        vector<int>nse(n);
        findNSE(heights,nse,n);
        findPSE(heights,pse,n);
        for(int i = 0;i<n;i++) {
            area = max(area, heights[i]*(nse[i]-pse[i]-1));
        }
        return area;
    }
};
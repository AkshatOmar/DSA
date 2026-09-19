class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        int idx = 0;
        int nse = n;
        int pse = -1;
        int area = 0;
        for(int i = 0;i<n;i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                idx = st.top();
                st.pop();
                nse = i;
                pse = st.empty() ? -1 : st.top();
                area = max(area,heights[idx]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()) {
            idx = st.top();
            st.pop();
            nse = n;
            pse = st.empty() ? -1 : st.top();
            area = max(area, heights[idx]*(nse-pse-1));
        }
        return area;
    }
};
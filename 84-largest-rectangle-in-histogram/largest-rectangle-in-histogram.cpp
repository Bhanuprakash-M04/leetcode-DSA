class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>st;
        int ans=0;
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int ele=heights[st.top()];
                st.pop();
                int pse=(st.empty()) ? -1 : st.top();
                int nse=i;
                ans=max(ans,(nse-pse-1)*ele);
            }
            st.push(i);
        }
        while(!st.empty()){
            int ele=heights[st.top()];
            st.pop();
            int nse=n;
            int pse=(st.empty()) ? -1 : st.top();
            ans=max(ans,(nse-pse-1)*ele);
        }
        return ans;
    }
};
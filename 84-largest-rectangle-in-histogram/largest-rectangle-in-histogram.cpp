class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>pse(n);
        vector<int>nse(n);
        pse=get_pse(heights);
        nse=get_nse(heights);
        int area=0;
        for(int i=0;i<n;i++){
            int len=nse[i]-pse[i]-1;
            area=max(area,heights[i]*len);
        }
        return area;
    }
    vector<int>get_pse(vector<int>& heights){
        vector<int>ans;
        stack<int>st;
        int n=heights.size();
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i])
                st.pop();
            if(st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    vector<int>get_nse(vector<int>heights){
        int n=heights.size();
        vector<int>ans;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()]>heights[i])
                st.pop();
            if(st.empty())
                ans.push_back(n);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
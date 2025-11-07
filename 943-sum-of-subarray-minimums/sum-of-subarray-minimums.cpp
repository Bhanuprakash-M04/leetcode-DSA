class Solution {
public:
    int m=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        vector<int>pse(n);
        vector<int>nse(n);
        pse=get_pse(arr);
        nse=get_nse(arr);
        for(int i=0;i<n;i++){
            int l=i-pse[i];
            int r=nse[i]-i;
            cnt = (cnt + ((l % m) * 1LL * (r % m) % m * 1LL * (arr[i] % m)) % m) % m;
        }
        return cnt;
    }
    vector<int>get_nse(vector<int>& arr){
        int n=arr.size();
        vector<int>ans;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i])
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
    vector<int>get_pse(vector<int>& arr){
        int n=arr.size();
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i])
                st.pop();
            if(st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
};
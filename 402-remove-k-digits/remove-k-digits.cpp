class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        stack<char>st;
        if(n<=k)
            return "0";
        int i=0;
        while(i<n){
            while(!st.empty() && k>0 && st.top()>num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
            i++;
        }
        while(k>0 && !st.empty()){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        int ind=0;
        for(char ch:ans){
            if(ch=='0')
                ind++;
            else
                break;
        }
        if(ind==ans.length())
            return "0";
        return ans.substr(ind);
    }
};
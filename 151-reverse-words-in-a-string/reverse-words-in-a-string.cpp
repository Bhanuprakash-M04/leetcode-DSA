class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string tmp="";
        for(int i=0;i<s.length();i++){
            if(s[i]!=' '){
                tmp+=s[i];
            }
            else{
                if(tmp!="")
                    st.push(tmp);
                tmp="";
            }
        }
        if(tmp!="")
            st.push(tmp);
        string ans="";
        while(!st.empty()){
            if(ans!="")
                ans=ans+" "+st.top();
            else   
                ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
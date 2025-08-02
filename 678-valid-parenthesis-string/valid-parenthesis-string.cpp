class Solution {
public:
    bool checkValidString(string s) {
        stack<pair<char,int>>st;
        int cnt=0;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(')
            {
                st.push({'(',cnt});
            }
            else if(s[i]=='*'){
                cnt++;
            }
            else {
                if(!st.empty()){
                    st.pop();
                }
                else if(cnt!=0){
                    cnt--;
                }
                else{
                    return false;
                }
            }
        }
        while(!st.empty()){
            int pre=st.top().second;
            st.pop();
            if(cnt-pre==0)
                return false;
            cnt--;
        }
        return true;
    }
};
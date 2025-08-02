class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string main;
        string tmp;
        for(int i=0;i<s.length();i++){
            tmp+=s[i];
            if(s[i]=='(')
                cnt++;
            else
                cnt--;
            if(cnt==0){
                for(int j=1;j<tmp.length()-1;j++){
                    main+=tmp[j];
                }
                tmp="";
            }
        }
        return main;
    }
};
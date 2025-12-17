class Solution {
public:
    bool isPalindrome(string s) {
        for(int i=0;i<s.length();i++){
            s[i]=toupper(s[i]);
        }
        string res="";
        for(char ch:s){
            if((ch>='A' && ch <='Z') || (ch>='0' && ch<='9'))
                res+=ch;
        }
        return check(res,0,res.length());
    }
    bool check(string& str,int i,int n){
        if(i>=n/2)
            return true;
        if(str[i]!=str[n-i-1])
            return false;
        return check(str,i+1,n);
    }
};
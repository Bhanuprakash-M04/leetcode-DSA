class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        long long ans=0;
        bool sign=true;
        bool flag=true;
        int val='+';
        for(int i=0;i<n;i++){
            if(s[i]==' ' && flag){
                continue;
            }
            else if((s[i]=='+' || s[i]=='-')){
                if(ans==0 && sign && flag){
                    val=s[i];
                    sign=false;
                    flag=false;
                }
                else
                    break;
            }
            else if(s[i]>='0' && s[i]<='9')
            {
                flag=false;
                ans=(ans*10)+(s[i]-'0');
                if(-ans<INT_MIN && val=='-')
                    return INT_MIN;
                if(ans>INT_MAX && val=='+')
                    return INT_MAX;
            }
            else
                break;
        }
        if(val=='-')
            ans=-ans;
        return ans;
    }
};
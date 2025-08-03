class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        int i=0;
        bool flag=false;
        long res=0;
        char val='+';
        while(i<n){
            if(s[i]==' '){
                if(res==0 && !flag && val=='+')
                {
                    i++;
                    continue;
                }
                else
                    break;
            }
            else if((s[i]=='+' || s[i]== '-') && res==0 && !flag)
            {
                val=s[i];
                flag=true;
            }
            else if(s[i]=='+' || s[i]== '-')
                break;
            else if(s[i]>='0' && s[i]<='9'){
                flag=true;
                res=res*10+(s[i]-'0');
                if(-res<INT_MIN && val=='-')
                    return INT_MIN;
                if(res>INT_MAX && val=='+')
                    return INT_MAX;
            }
            else{
                break;
            }
            i++;
            
        }
        if(val=='-')
            res=-res;
        return res;
        
    }
};
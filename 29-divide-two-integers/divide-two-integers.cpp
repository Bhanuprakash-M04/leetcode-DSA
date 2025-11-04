class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor)
            return 1;
        bool sign=true;
        if((dividend<=0 && divisor>0) || (dividend>=0 && divisor<0))
            sign=false;
        if(dividend==INT_MIN && divisor==-1)
            return INT_MAX;
        if(dividend==INT_MIN && divisor==1)
            return INT_MIN;
        long long nume=llabs((long long)dividend);
        long long deno=llabs((long long)divisor);
        long ans=0;
        while(nume>=deno){
            int cnt=0;
            while(nume>=deno<<(cnt+1)){
                cnt++;
            }
            ans=ans+(1<<cnt);
            nume=nume-(deno<<cnt);
        }
        if(ans>INT_MAX && sign==true)
            return INT_MAX;
        if(ans>INT_MAX && sign==false)
            return INT_MIN;
        return (sign) ? ans : -ans;

    }
};
class Solution {
public:
    double solve(double ans,double x,long long n){
        if(n==0)
            return ans;
        if(n%2==0)
            return solve(ans,x*x,n/2);
        else
            return solve(ans*x,x,n-1);
    }
    double myPow(double x, int n) {
        long long val=n;
        if(n<0)
        {
            x=1/x;
            val=-val;
        }
        return solve(1,x,val);
    }
};
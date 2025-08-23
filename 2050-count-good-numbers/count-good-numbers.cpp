class Solution {
public:
    int m=1e9+7;
    long long solve(long long ans,long long base,long long power){
        if(power==0)
            return ans;
        if(power%2==0)
            return solve(ans,(base*base)%m,power/2);
        else
            return solve((ans*base)%m,base,power-1);
    }
    int countGoodNumbers(long long n) {
        long long even=(n+1)/2;
        long long odd=(n/2);
        return (solve(1,5,even)%m * solve(1,4,odd)%m)%m;
    }
};
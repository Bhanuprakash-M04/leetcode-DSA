class Solution {
public:
    int reverse(int x) {
        long long rev=0;
        while(x!=0)
        {
            int a=x%10;
            rev=rev*10+a;
            x=x/10;
            if(rev>INT_MAX || rev<INT_MIN)
                return 0;
        }
        return rev;
    }
};
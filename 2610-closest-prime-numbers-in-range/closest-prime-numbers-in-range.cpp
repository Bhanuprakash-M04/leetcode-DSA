class Solution {
public:
    bool isprime(int n)
    {
        if(n==1)
            return false;
        for(int i=2;i<=sqrt(n);i++)
        {
            if(n%i==0)
                return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int>prime;
        for(int i=left;i<=right;i++)
        {
            if(isprime(i))
                prime.push_back(i);
        }
        if(prime.size()<2)
            return {-1,-1};
        else
        {
            int ans=INT_MAX;
            int a=-1;
            int b=-1;
            for(int i=0;i<prime.size()-1;i++)
            {
                if(ans>prime[i+1]-prime[i])
                {
                    a=prime[i+1];
                    b=prime[i];
                    ans=prime[i+1]-prime[i];
                }
            }
            return {b,a};
        }
    }
};
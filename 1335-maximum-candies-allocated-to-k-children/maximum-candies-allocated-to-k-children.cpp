class Solution {
public:
    bool allocate(vector<int>& candies, long long k, long long x)
    {
        long long cnt=0;
        for(int candy:candies)
            cnt+=candy/x;
        return cnt>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        long long low=1;
        long long high=*max_element(candies.begin(),candies.end());
        long long res=0;
        while(low<=high)
        {
            long long mid=(low+high)/2;
            if(mid==0)
                break;
            if(allocate(candies,k,mid))
            {
                res=mid;
                low=mid+1;
            }
            else
                high=mid-1;
        }
        return res;
    }   
};
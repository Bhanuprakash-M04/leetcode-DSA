class Solution {
public:
    bool check(vector<int>&piles,int h,int mid){
        int n=piles.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            if(piles[i]<=mid)
                cnt++;
            else if(piles[i]%mid!=0)
                cnt+=((piles[i]/mid)+1);
            else
                cnt+=((piles[i]/mid));
        }
        if(cnt>h)
            return false;
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(piles,h,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
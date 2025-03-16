class Solution {
public:
    bool canRepair(vector<int>& ranks,int cars,long long mid)
    {
        long long total_cars=0;
        for(int r:ranks)
        {
            if(mid<r)
                continue;
            total_cars+=(long long)(sqrt((double)mid/r));
            if(total_cars>=cars)
                return true;
        }
        return total_cars>=cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long left=1;
        long long right=(long long)*min_element(ranks.begin(),ranks.end())*(long long)cars*(long long)cars;
        long long ans=right;
        while(left<=right)
        {
            long long mid=left+(right-left)/2;
            if(canRepair(ranks,cars,mid)){
                ans=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return ans;
    }
};
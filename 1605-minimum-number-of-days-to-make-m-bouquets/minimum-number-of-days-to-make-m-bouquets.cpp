class Solution {
public:
    bool check(vector<int>& bloomDay,int m,int k,int mid){
        int n=bloomDay.size();
        int cnt=0;
        int total=0;
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid){
                cnt++;
            }
            else{
                int val=cnt/k;
                cnt=0;
                total+=val;
            }
        }
        total+=cnt/k;
        return total>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int mini=INT_MAX;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            maxi=max(maxi,bloomDay[i]);
            mini=min(mini,bloomDay[i]);
        }
        int low=mini;
        int high=maxi;
        int ans=INT_MAX;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(bloomDay,m,k,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
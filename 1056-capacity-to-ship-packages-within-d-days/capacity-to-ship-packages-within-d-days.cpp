class Solution {
public:
    bool check(vector<int>&weights,int days,int mid){
        int n=weights.size();
        int total_days=0;
        int cur_sum=0;
        for(int i=0;i<n;i++){
            if(cur_sum+weights[i]<=mid){
                cur_sum+=weights[i];
            }
            else{
                total_days++;
                cur_sum=weights[i];
            }
        }
        if(cur_sum!=0)
            total_days++;
        return total_days<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int n=weights.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=weights[i];
        }
        int high=sum;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(weights,days,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};
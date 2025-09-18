class Solution {
public:
    int check(vector<int>&nums ,int mid){
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]<=mid)
                sum++;
            else if(nums[i]%mid==0)
                sum+=(nums[i]/mid);
            else
                sum+=(nums[i]/mid)+1;
        }
        return sum;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(nums,mid)<=threshold){
                ans=mid;
                high=mid-1;
            }
            else
                low=mid+1;
        }
        return ans;
    }
};
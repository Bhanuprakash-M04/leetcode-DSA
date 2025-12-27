class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return valid(nums,k)-valid(nums,k-1);
    }
    int valid(vector<int>& nums,int k){
        int n=nums.size();
        int left=0;
        int odd_cnt=0;
        int ans=0;
        for(int right=0;right<n;right++){
            if(nums[right]&1)
                odd_cnt++;
            while(odd_cnt>k){
                if(nums[left]&1)
                    odd_cnt--;
                left++;
            }
            ans+=(right-left+1);
        }
        return ans;
    }
};
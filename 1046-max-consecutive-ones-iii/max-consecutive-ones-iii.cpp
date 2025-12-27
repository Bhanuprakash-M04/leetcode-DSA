class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=0;
        int left=0;
        int cnt=0;
        for(int right=0;right<n;right++){
            if(nums[right]==0)
                cnt++;
            if(cnt>k){
                if(nums[left]==0)
                    cnt--;
                left++;
            }
            if(cnt<=k)
                ans=max(ans,right-left+1);
        }
        return ans;
    }
};
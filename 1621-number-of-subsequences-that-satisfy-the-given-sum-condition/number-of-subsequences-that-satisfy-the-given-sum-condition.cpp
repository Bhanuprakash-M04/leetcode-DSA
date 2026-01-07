class Solution {
public:
    int m=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int>power(n);
        power[0]=1;
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            power[i]=(power[i-1]*2)%m;
        }
        int left=0;
        int right=n-1;
        int cnt=0;
        while(left<=right){
            if(nums[left]+nums[right]<=target){
                cnt=(cnt+power[right-left])%m;
                left++;
            }
            else
                right--;
        }
        return cnt;
    }
};
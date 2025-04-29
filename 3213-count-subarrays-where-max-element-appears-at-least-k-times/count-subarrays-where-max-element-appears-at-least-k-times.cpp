class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxElement=*max_element(nums.begin(),nums.end());
        long long ans=0;
        int cnt=0;
        int start=0;
        for(int i=0;i<n;i++){
            if(nums[i]==maxElement)
                cnt++;
            while(cnt==k){
                if(nums[start]==maxElement)
                    cnt--;
                start++;
            }
            ans+=start;
        }
        return ans;
    }
};
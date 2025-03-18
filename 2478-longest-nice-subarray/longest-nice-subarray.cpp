class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0,max_len=0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            while((nums[i]&ans)!=0)
            {
                ans^=nums[l];
                l++;
            }
            ans|=nums[i];
            max_len=max(max_len,i-l+1);
        }
        return max_len;

    }
};
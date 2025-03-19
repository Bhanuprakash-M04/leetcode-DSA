class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        for(int i=0;i<n-2;i++)
        {
            if(nums[i]!=1)
            {
                int p1=i;
                int p2=i+2;
                while(p1<=p2 && p2<n)
                {
                    if(nums[p1]==1)
                        nums[p1]=0;
                    else if(nums[p1]==0)
                        nums[p1]=1;
                    p1++;
                }
                cnt++;
            }
        }
        if(nums[n-1]==0 || nums[n-2]==0)
            return -1;
        return cnt;
        
        
    }
};
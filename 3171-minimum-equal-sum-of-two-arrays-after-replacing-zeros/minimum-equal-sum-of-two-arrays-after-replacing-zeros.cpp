class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        long long zero1=0,zero2=0,sum1=0,sum2=0;
        for(int i=0;i<n1;i++)
        {
            if(nums1[i]==0)
            {
                zero1++;
                sum1++;
            }
            sum1+=nums1[i];
        }
          for(int i=0;i<n2;i++)
        {
            if(nums2[i]==0)
            {
                zero2++;
                sum2++;
            }
            sum2+=nums2[i];
        }
        if(!zero1 && sum2>sum1 || !zero2 && sum1>sum2)
            return -1;
        return max(sum1,sum2);


    }
};
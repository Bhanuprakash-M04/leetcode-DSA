class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=0;
        int mini=0;
        int sum=0;
        for(int i:nums)
        {
            sum+=i;
            if(sum>maxi)
                maxi=max(sum,maxi);
            if(sum<mini)
                mini=min(sum,mini);
        }
        return abs(maxi-mini);
    }
};
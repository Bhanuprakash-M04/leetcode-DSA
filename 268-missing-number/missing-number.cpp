class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=*max_element(nums.begin(),nums.end());
        unordered_set<int>myset;
        for(auto num:nums)
        {
            myset.insert(num);
        }
        for(int i=0;i<=n;i++)
        {
            if(myset.find(i)==myset.end())
                return i;
        }
        return n+1;
    }
};
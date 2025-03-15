class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        unordered_set<int>myset;
        for(auto num:nums)
        {
            myset.insert(num);
        }
        for(int i=1;i<=n;i++)
        {
            if(myset.find(i)==myset.end())
                ans.push_back(i);
        }
        return ans;
    }
};
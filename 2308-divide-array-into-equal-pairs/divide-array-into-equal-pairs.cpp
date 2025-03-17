class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int>myset;
        for(int num:nums)
        {
            if(myset.find(num)!=myset.end())
                myset.erase(num);
            else
                myset.insert(num);
        }
        if(myset.size()==0)
            return true;
        else
            return false;
    }
};
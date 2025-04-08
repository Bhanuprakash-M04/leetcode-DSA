class Solution {
public:
    bool containsduplicate(vector<int>& nums)
    {
        unordered_set<int>myset;
        for(int i=0;i<nums.size();i++)
        {
            if(myset.find(nums[i])!=myset.end())
                return true;
            myset.insert(nums[i]);
        }
        return false;
    }
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        while(nums.size()>=3)
        {
            if(containsduplicate(nums))
            {
                if(nums.size()>=3)
                    nums.erase(nums.begin(),nums.begin()+3);
                cnt++;
            }
            else
            {
                return cnt;
            }
             for(int i=0;i<nums.size();i++)
            {
                cout << nums[i] << " ";
            }
            cout << endl;
        }
        if(nums.size()<3 && containsduplicate(nums))
            cnt++;
        return cnt;
    }
};
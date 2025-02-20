class Solution {
public:
    void backtrack(int n,string curr,vector<string>& ans)
    {
        if(curr.length()==n)
        {
            ans.push_back(curr);
            return;
        }
        backtrack(n,curr+'0',ans);
        backtrack(n,curr+'1',ans);
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        vector<string>ans;
        backtrack(n,"",ans);
        unordered_set<string>myset;
        for(auto i:nums)
            myset.insert(i);
        for(auto j:ans)
        {
            if(myset.find(j)==myset.end())
                return j;
        }
        return " ";
    }
};
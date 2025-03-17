class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mymap;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int x=target-nums[i];
            if(mymap.find(x)!=mymap.end())
                return {i,mymap[x]};
            mymap[nums[i]]=i;
        }
        return { };
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mymap;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(mymap.find(target-nums[i])!=mymap.end()){
                return {i,mymap[target-nums[i]]};
            }
            mymap[nums[i]]=i;
        }
        return {};
    }
};
class Solution {
public:
    void generate(int ind,vector<vector<int>>& ans,vector<int>& nums,vector<int>& curr){
        ans.push_back(curr);
        for(int i=ind;i<nums.size();i++){
            if(i>ind && nums[i]==nums[i-1])
                continue;
            curr.push_back(nums[i]);
            generate(i+1,ans,nums,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        sort(nums.begin(),nums.end());
        generate(0,ans,nums,curr);
        return ans;
    }
};
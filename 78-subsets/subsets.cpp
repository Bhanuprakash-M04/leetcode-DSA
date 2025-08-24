class Solution {
public:
    void generate(vector<int>& nums,vector<vector<int>>&ans,vector<int>&curr,int i){
        if(i==nums.size())
        {
            ans.push_back(curr);
            return;
        }
        generate(nums,ans,curr,i+1);
        curr.push_back(nums[i]);
        generate(nums,ans,curr,i+1);
        curr.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        generate(nums,ans,curr,0);
        return ans;
    }
};
class Solution {
public:
    void generate(int ind,vector<vector<int>>& ans,vector<int>& candidates,int target,int n,vector<int>curr){
        if(target<=0 || ind >=n){
            if(target==0){
                ans.push_back(curr);
            }
            return ;
        }
        target-=candidates[ind];
        curr.push_back(candidates[ind]);
        generate(ind,ans,candidates,target,n,curr);
        target+=candidates[ind];
        curr.pop_back();
        generate(ind+1,ans,candidates,target,n,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        int n=candidates.size();
        vector<int>curr;
        generate(0,ans,candidates,target,n,curr);
        return ans;
    }
};
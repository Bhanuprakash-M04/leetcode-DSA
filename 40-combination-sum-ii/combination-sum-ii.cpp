class Solution {
public:
    void generate(int ind,vector<vector<int>>& ans,vector<int>& curr,vector<int>& candidates,int target){
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        for(int i=ind;i<candidates.size();i++){
            if(i>ind && candidates[i]==candidates[i-1])
                continue;
            if(candidates[i]>target)
                break;
            target-=candidates[i];
            curr.push_back(candidates[i]);
            generate(i+1,ans,curr,candidates,target);
            target+=candidates[i];
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>curr;
        generate(0,ans,curr,candidates,target);
        return ans;
    }
};
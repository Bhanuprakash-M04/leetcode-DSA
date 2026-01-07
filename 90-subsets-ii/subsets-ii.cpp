class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int num=0;num<(1<<n);num++){
            vector<int>curr;
            for(int i=0;i<n;i++){
                if(num&(1<<i))
                    curr.push_back(nums[i]);
            }
            res.insert(curr);
        }
        vector<vector<int>>ans;
        for(auto it:res){
            ans.push_back(it);
        }
        return ans;
    }
};
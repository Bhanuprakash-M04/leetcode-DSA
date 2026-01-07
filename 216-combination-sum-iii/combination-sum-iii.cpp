class Solution {
public:
    void generate( vector<vector<int>>& ans,vector<int>& curr,int sum,int k,int n,int ind){
        if(sum==n && k==0){
            ans.push_back(curr);
            return ;
        }
        if(sum>n || k<0)
            return ;
        for(int i=ind;i<10;i++){
            sum+=i;
            curr.push_back(i);
            k--;
            generate(ans,curr,sum,k,n,i+1);
            k++;
            sum-=i;
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>curr;
        generate(ans,curr,0,k,n,1);
        return ans;
    }
};
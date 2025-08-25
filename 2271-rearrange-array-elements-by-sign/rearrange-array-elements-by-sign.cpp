class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        vector<int>pos;
        vector<int>neg;
        for(int num:nums){
            if(num<0)
                neg.push_back(num);
            else
                pos.push_back(num);
        }
        int e=0;
        int o=0;
        for(int i=0;i<n;i++){
            if(i%2==0){
                ans[i]=pos[e++];
            }
            else
                ans[i]=neg[o++];
        }
        return ans;
    }
};
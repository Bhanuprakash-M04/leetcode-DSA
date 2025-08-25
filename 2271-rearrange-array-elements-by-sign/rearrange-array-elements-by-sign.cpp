class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n);
        int p1=0;
        int p2=1;
        for(int num:nums){
            if(num<0){
                ans[p2]=num;
                p2+=2;
            }
            else{
                ans[p1]=num;
                p1+=2;
            }
        }
        return ans;
    }
};
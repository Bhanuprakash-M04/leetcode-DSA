class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int pre_product=1;
        int suf_product=1;
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pre_product*=nums[i];
            suf_product*=nums[n-i-1];
            maxi=max(maxi,pre_product);
            maxi=max(maxi,suf_product);
            if(pre_product==0)
                pre_product=1;
            if(suf_product==0)
                suf_product=1;
        }
        return maxi;
    }
};
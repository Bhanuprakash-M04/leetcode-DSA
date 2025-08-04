class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n);
        k=k%n;
        for(int i=0;i<n;i++){
            ans[i]=nums[(n-k+i)%n];
        }
        for(int i=0;i<n;i++){
            nums[i]=ans[i];
        }
    }
};
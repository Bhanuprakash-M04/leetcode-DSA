class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            int j=i+1;
            while(i!=j%n){
                if(nums[i]<nums[j%n]){
                    ans.push_back(nums[j%n]);
                    break;
                }
                j++;
            }
            if(i==j%n)
                ans.push_back(-1);
        }
        return ans;
    }
};
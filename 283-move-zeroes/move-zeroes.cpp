class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       int p1=0;
       int p2=1;
       while(p2<nums.size()) 
       {
            if(nums[p1]==0 && nums[p2]!=0)
            {
                swap(nums[p1],nums[p2]);
                p1++;
            }
            if(nums[p1]!=0){
                p1++;
            }
            p2++;
       }
    }
};
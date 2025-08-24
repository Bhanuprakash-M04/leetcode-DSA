class Solution {
public:
    void sortColors(vector<int>& nums) {
        //DUTCH NATIONAL FLAG ALGORITHM
        int p1=0;
        int p2=0;
        int p3=nums.size()-1;
        while(p2<=p3){
            if(nums[p2]==0){
                swap(nums[p2],nums[p1]);
                p1++;
                p2++;
            }
            else if(nums[p2]==1){
                p2++;
            }
            else{
                swap(nums[p2],nums[p3]);
                p3--;
            }
        }
    }
};
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return valid(nums,k)-valid(nums,k-1);
    }
    int valid(vector<int>& nums,int k){
        int n=nums.size();
        int left=0;
        int ans=0;
        unordered_map<int,int>mymap;
        for(int right=0;right<n;right++){
            mymap[nums[right]]++;
            while(mymap.size()>k){
                mymap[nums[left]]--;
                if(mymap[nums[left]]==0)
                    mymap.erase(nums[left]);
                left++;
            }
            if(mymap.size()<=k)
                ans+=(right-left+1);
        }
        return ans;
    }
};
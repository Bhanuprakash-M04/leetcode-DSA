class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return subarrayLessEquals(nums,goal)-subarrayLessEquals(nums,goal-1);
    }
    int subarrayLessEquals(vector<int>& nums,int goal){
        int left=0;
        int ans=0;
        int sum=0;
        int n=nums.size();
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(sum>goal && left<=right){
                sum-=nums[left];
                left++;
            }
            ans+=(right-left+1);
        }
        return ans;
    }
};



// TC:O(n)
// SC:O(N)
// int n=nums.size();
//         unordered_map<int,int>mymap;
//         int sum=0;
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             sum+=nums[i];
//             if(sum==goal)
//                 cnt++;
//             if(mymap.find(sum-goal)!=mymap.end())
//                 cnt+=mymap[sum-goal];
//             mymap[sum]++;
//         }
//         return cnt;
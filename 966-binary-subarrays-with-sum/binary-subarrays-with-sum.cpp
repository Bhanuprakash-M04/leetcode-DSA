class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        unordered_map<int,int>mymap;
        int sum=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==goal)
                cnt++;
            if(mymap.find(sum-goal)!=mymap.end())
                cnt+=mymap[sum-goal];
            mymap[sum]++;
        }
        return cnt;
    }
};
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt=0;
        unordered_map<int,int>mymap;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                cnt++;
            }
            if(mymap.find(sum-k)!=mymap.end()){
                cnt+=mymap[sum-k];
            }
            mymap[sum]++;
        }
        return cnt;
    }
};
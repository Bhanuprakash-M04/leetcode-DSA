class Solution {
public:
    int m=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int p1=0;
        int p2=nums.size()-1;
        int cnt=0;
        vector<int>pow2(nums.size());
        pow2[0]=1;
        for(int i=1;i<nums.size();i++){
            pow2[i]=(pow2[i-1]*2)%m;
        }
        while(p1<=p2){
            if(nums[p1]+nums[p2]<=target){
                long long x=p2-p1;
                cnt=(cnt+pow2[x])%m;
                p1++;
            }
            else{
                p2--;
            }
        }
        return cnt;
    }
};
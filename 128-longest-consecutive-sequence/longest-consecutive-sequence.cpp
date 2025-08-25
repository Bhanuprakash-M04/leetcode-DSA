class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>myset;
        for(int num:nums){
            myset.insert(num);
        }
        int maxi=0;
        for(int num:myset){
            int cnt=1;
            if(myset.find(num-1)==myset.end()){
                int curr=num;
                while(myset.find(curr+1)!=myset.end()){
                    cnt++;
                    curr++;
                }
                maxi=max(maxi,cnt);
            }
        }
        return maxi;
    }
};
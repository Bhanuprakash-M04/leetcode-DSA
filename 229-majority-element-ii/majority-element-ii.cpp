class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int>mymap;
        int n=nums.size();
        for(int num:nums){
            mymap[num]++;
        }
        vector<int>ans;
        for(auto it:mymap){
            int x=it.second;
            if(x>n/3)
                ans.push_back(it.first);
        }
        return ans;
    }
};
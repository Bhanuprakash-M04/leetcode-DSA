class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mymap;
        for(int num:nums)
            mymap[num]++;
        priority_queue<pair<int,int>>pq;
        for(auto it:mymap){
            pq.push({it.second,it.first});
        }
        vector<int>ans;
        while(k>0 && !pq.empty()){
            auto it=pq.top();
            ans.push_back(it.second);
            pq.pop();
            k--;
        }
        return ans;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>>pq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
        }
        int cnt=0;
        while(pq.size()>=2 && pq.top()<k)
        {
            long long min1=pq.top();
            pq.pop();
            long long min2=pq.top();
            pq.pop();
            long long ans=min1*2+min2;
            pq.push(ans);
            cnt++;
        }
        return cnt;
    }
};
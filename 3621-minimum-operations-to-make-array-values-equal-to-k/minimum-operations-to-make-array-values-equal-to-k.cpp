class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]<k)
                return -1;
        }
        nums.push_back(k);
        priority_queue<int>pq;
        for(int num:nums)
            pq.push(num);
        int cnt=-1;
        while(pq.top()>=k)
        {
            if(pq.top()==k)
            {
                return cnt+1;
            }
            int prev_pop=pq.top();
            while(prev_pop==pq.top())
                pq.pop();
            cnt++;
        }
        return -1;
    }
};
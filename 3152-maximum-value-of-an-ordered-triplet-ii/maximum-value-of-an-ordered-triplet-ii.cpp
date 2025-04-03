class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=INT_MIN;
        int n=nums.size();
        vector<int>pre_max(n);
        vector<int>suf_max(n);
        pre_max[0]=0;
        suf_max[n-1]=0;
        for(int i=1;i<n;i++)
        {
            pre_max[i]=max(pre_max[i-1],nums[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            suf_max[i]=max(suf_max[i+1],nums[i+1]);
        }
        for(int i=0;i<n;i++)
        {
            ans=max(ans,((long long)pre_max[i]-nums[i])*suf_max[i]);
        }
        // for(int i=0;i<n;i++)
        //     cout << pre_max[i] << " ";
        // cout << endl;
        // for(int i=0;i<n;i++)
        //     cout << suf_max[i] << " ";
        // cout << endl;
        return ans;
    }
};
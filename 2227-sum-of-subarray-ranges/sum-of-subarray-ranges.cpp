class Solution {
public:
    // just perform sum of subarray maximums - sum of subarray minimums
    long long subArrayRanges(vector<int>& nums) {
        long long sum=sub_max(nums)-sub_min(nums);
        return sum;
    }
    long long sub_min(vector<int>& nums){
        int n=nums.size();
        vector<int>nse;
        vector<int>pse;
        nse=get_nse(nums);
        pse=get_pse(nums);
        long long sum=0;
        for(int i=0;i<n;i++){
            int l=i-pse[i];
            int r=nse[i]-i;
            long long res=(l*r*1LL*nums[i]);
            sum+=res;
        }
        return sum;
    }
    vector<int>get_nse(vector<int>& nums){
        int n=nums.size();
        stack<int>st;
        vector<int>ans;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]>=nums[i])
                st.pop();
            if(st.empty())
                ans.push_back(n);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int>get_pse(vector<int>& nums){
        int n=nums.size();
        stack<int>st;
        vector<int>ans;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]>nums[i])
                st.pop();
            if(st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
    long long sub_max(vector<int>& nums){
        int n=nums.size();
        vector<int>nge(n);
        vector<int>pge(n);
        nge=get_nge(nums);
        pge=get_pge(nums);
        long long sum=0;
        for(int i=0;i<n;i++){
            int l=i-pge[i];
            int r=nge[i]-i;
            long long res=(l*r*1LL*nums[i]);
            sum+=res;
        }
        return sum;
    }
    vector<int>get_nge(vector<int>& nums){
        int n=nums.size();
        vector<int>ans;
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && nums[st.top()]<=nums[i])
                st.pop();
            if(st.empty())
                ans.push_back(n);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    vector<int>get_pge(vector<int>& nums){
        int n=nums.size();
        vector<int>ans;
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && nums[st.top()]<nums[i])
                st.pop();
            if(st.empty())
                ans.push_back(-1);
            else
                ans.push_back(st.top());
            st.push(i);
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            int j=i+1;
            while(i!=j%n){
                if(nums[i]<nums[j%n]){
                    st.push(nums[j%n]);
                    break;
                }
                j++;
            }
            if(i==j%n)
                st.push(-1);
        }
        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
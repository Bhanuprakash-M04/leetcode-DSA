class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j%n<n){
                if(i==j%n){
                    st.push(-1);
                    break;
                }
                if(nums[i]<nums[j%n]){
                    st.push(nums[j%n]);
                    break;
                }
                j++;
            }
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
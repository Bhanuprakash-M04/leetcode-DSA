class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        stack<int>st;
        unordered_map<int,int>mymap;
        for(int i=m-1;i>=0;i--){
            while(!st.empty() && nums2[i]>=st.top())
                st.pop();
            if(st.empty()){
                mymap[nums2[i]]=-1;
                st.push(nums2[i]);
            }
            else{
                mymap[nums2[i]]=st.top();
                st.push(nums2[i]);
            }
        }
        for(int num:nums1){
             ans.push_back(mymap[num]);
        }
        return ans;
    }
};
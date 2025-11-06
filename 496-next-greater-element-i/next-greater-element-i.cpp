class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++){
            int j=0;
            while(j<m && nums1[i]!=nums2[j]){
                j++;
            }
            j++;
            while(j<m && nums1[i]>nums2[j]){
                j++;
            }
            if(j<m)
                ans.push_back(nums2[j]);
            else
                ans.push_back(-1);
        }
        return ans;
    }
};
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int>temp(n+m);
        int p1=0;
        int p2=0;
        int k=0;
        while(p1<n && p2<m){
            if(nums1[p1]<nums2[p2])
                temp[k++]=nums1[p1++];
            else
                temp[k++]=nums2[p2++];
        }
        while(p1<n){
            temp[k++]=nums1[p1++];
        }
        while(p2<m){
            temp[k++]=nums2[p2++];
        }
        return (n+m)%2==0 ? (((double)temp[(n+m)/2]+(double)temp[(n+m)/2-1])/2) : (double)temp[(n+m)/2];
    }
};
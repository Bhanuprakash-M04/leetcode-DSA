class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x=nums1.size();
        int p1=x-1;
        int p2=n-1;
        int p3=m-1;
        while(p2>=0 && p3>=0){
            if(nums1[p3]>nums2[p2]){
                nums1[p1]=nums1[p3];
                p3--;
            }
            else{
                nums1[p1]=nums2[p2];
                p2--;
            }
            p1--;
        }
        while(p2>=0){
            nums1[p1]=nums2[p2];
            p1--;
            p2--;
        }
    }
};
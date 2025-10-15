class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int sec_ind=(n+m)/2;
        int first_ind=sec_ind-1;
        int first_ele=-1,sec_ele=-1;
        int p1=0, p2=0,cnt=0;
        while(p1<n && p2<m){
            if(nums1[p1]<nums2[p2]){
                if(cnt==first_ind)
                    first_ele=nums1[p1];
                if(cnt==sec_ind)
                    sec_ele=nums1[p1];
                p1++;
                cnt++;
            }
            else{
                if(cnt==first_ind)
                    first_ele=nums2[p2];
                if(cnt==sec_ind)
                    sec_ele=nums2[p2];
                p2++;
                cnt++;
            }
            if(sec_ele!=-1)
                break;
        }
        while(p1<n && sec_ele==-1){
            if(cnt==first_ind)
                first_ele=nums1[p1];
            if(cnt==sec_ind)
                sec_ele=nums1[p1];
            p1++;
            cnt++;
        }
        while(p2<m && sec_ele==-1){
            if(cnt==first_ind)
                first_ele=nums2[p2];
            if(cnt==sec_ind)
                sec_ele=nums2[p2];
            p2++;
            cnt++;
        }
        return (n+m)%2==0 ? ((double)first_ele+(double)sec_ele)/2 : (double)sec_ele;
    }
};
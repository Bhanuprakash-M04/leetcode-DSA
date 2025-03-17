class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int max_len=0;
        for(int i=1;i<n-1;i++)
        {
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
            {
                int left=i-1;
                int right=i+1;
                while(left>0 && arr[left-1]<arr[left])
                {
                    left--;
                }
                while(right+1<n && arr[right]>arr[right+1])
                {
                    right++;
                }
                max_len=max(max_len,right-left+1);
            }
        }
        return max_len;
    }
};
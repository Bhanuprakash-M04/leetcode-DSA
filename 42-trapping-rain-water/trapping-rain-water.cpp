class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int ans=0;
        int left=0,right=n-1;
        int l_max=0,r_max=0;
        while(left<right){
            if(height[left]<=height[right]){
                if(height[left]<l_max)
                    ans+=(l_max-height[left]);
                else
                    l_max=height[left];
                left=left+1;
            }
            else{
                if(height[right]<r_max)
                    ans+=(r_max-height[right]);
                else
                    r_max=height[right];
                right=right-1;
            }
        }
        return ans;
    }
};
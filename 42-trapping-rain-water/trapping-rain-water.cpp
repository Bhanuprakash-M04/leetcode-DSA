class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>pre(n);
        vector<int>suf(n);
        int maxi=0;
        for(int i=0;i<n;i++){
            pre[i]=maxi;
            maxi=max(maxi,height[i]);
        }
        maxi=0;
        for(int i=n-1;i>=0;i--){
            suf[i]=maxi;
            maxi=max(maxi,height[i]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            int val=max(0,min(pre[i],suf[i])-height[i]);
            cnt+=val;
        }
        return cnt;
    }
};
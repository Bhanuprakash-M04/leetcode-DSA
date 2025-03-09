class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int len=1,ans=0;
        int n=colors.size();
        for(int i=1;i<=n+k-2;i++)
        {
            if(colors[i%n]!=colors[(i-1+n)%n])
            {
                len++;
            }
            else
                len=1;
            if(len>=k)
                ans++;
        }
        return ans;
    }
};
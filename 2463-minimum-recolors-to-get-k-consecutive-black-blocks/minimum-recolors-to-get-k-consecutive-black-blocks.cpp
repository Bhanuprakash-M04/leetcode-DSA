class Solution {
public:
    int count(string s)
    {
        int cnt=0;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='W')
                cnt++;
        }
        return cnt;
    }
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        int ans=INT_MAX;
        for(int i=0;i<=n-k;i++)
        {
            string s=blocks.substr(i,k);
            int x=count(s);
            ans=min(ans,x);
        }
        return ans;
    }
};
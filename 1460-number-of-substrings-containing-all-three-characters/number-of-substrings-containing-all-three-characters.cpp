class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        long long cnt=0;
        int lastA=-1,lastB=-1,lastC=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
                lastA=i;
            if(s[i]=='b')
                lastB=i;
            if(s[i]=='c')
                lastC=i;
            int mini=min(min(lastA,lastB),lastC);
            if(mini!=-1)
                cnt+=(mini+1);
        }
        return cnt;
    }
};
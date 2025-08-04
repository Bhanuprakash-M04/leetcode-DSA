class Solution {
public:
    int countHomogenous(string s) {
        int n=s.length();
        int m=1e9+7;
        long long cnt=1;
        long long ans=0;
        for(int i=0;i<n;i++){
            if(i+1<n && s[i]==s[i+1]){
                cnt++;
            }
            else{
                int val=(cnt*(cnt+1)/2)%m;
                ans=(ans+val)%m;
                cnt=1;
            }
        }
        return (int)ans;
    }
};
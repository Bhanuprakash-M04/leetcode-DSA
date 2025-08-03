class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            int p1=i;
            int p2=i;
            while(s[p1]==s[p2]){
                string res=s.substr(p1,p2-p1+1);
                if(res.length()>ans.length())
                ans=res; 
                p1--;
                p2++;
                if(p1==-1 || p2==n)
                    break;
            }
        }
        for(int i=0;i<n;i++){
            int p1=i;
            int p2=i+1;
            while(s[p1]==s[p2]){
                string res=s.substr(p1,p2-p1+1);
                if(res.length()>ans.length())
                ans=res; 
                p1--;
                p2++;
                if(p1==-1 || p2==n)
                    break;
            }
        }
        
        return ans;
    }
};
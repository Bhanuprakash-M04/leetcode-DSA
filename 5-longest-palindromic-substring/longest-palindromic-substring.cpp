class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        string ans="";
        for(int i=0;i<n;i++){
            string odd=palindrome(i,i,s);
            if(odd.length()>ans.length())
                ans=odd;
            string even=palindrome(i,i+1,s);
            if(even.length()>ans.length())
                ans=even;
        }
        
        return ans;
    }
    string palindrome(int p1,int p2,string s){
        string res="";
        while(p1>=0 && p2<s.length() && s[p1]==s[p2]){
            res=s.substr(p1,p2-p1+1);
            p1--;
            p2++;
            
        }
        return res;
    }
};
class Solution {
public:
    void generate(string& ans,int m,int n){
        if(m==n)
            return;
        ans=ans+"1"+reverse(ans);
        generate(ans,m+1,n);
    }
    string reverse(string ans){
        int n=ans.length();
        string rev="";
        for(int i=n-1;i>=0;i--){
            if(ans[i]=='1')
                rev+='0';
            else 
                rev+='1';
        }
        return rev;
    }

    
    char findKthBit(int n, int k) {
        string ans="0";
        generate(ans,1,n);
        return ans[k-1];
    }
    
};
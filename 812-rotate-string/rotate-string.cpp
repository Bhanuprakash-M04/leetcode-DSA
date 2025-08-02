class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.length();
        for(int i=0;i<n;i++){
            string st=rotate(s,i);
            if(st==goal)
                return true;
        }
        return false;
    }
    string rotate(string str,int val){
        string ans=str;
        int n=str.length();
        for(int i=0;i<n;i++){
            ans[i]=str[(i+val)%n];
        }
        return ans;
    }
};
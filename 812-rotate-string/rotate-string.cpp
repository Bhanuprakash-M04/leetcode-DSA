class Solution {
public:
    // bool rotateString(string s, string goal) {
    //     int n=s.length();
    //     for(int i=0;i<n;i++){
    //         string st=rotate(s,i);
    //         if(st==goal)
    //             return true;
    //     }
    //     return false;
    // }
    // string rotate(string str,int val){
    //     string ans=str;
    //     int n=str.length();
    //     for(int i=0;i<n;i++){
    //         ans[i]=str[(i+val)%n];
    //     }
    //     return ans;
    // }
    bool rotateString(string s, string goal){
        if(s.size()!=goal.size())
            return false;
        string full=s+s;
        int n=full.size();
        int m=goal.size();
        for(int i=0;i<n-m;i++){
            string sub_str=full.substr(i,m);
            if(sub_str==goal)
                return true;
        }
        return false;
    }

};
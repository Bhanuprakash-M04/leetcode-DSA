class Solution {
public:
    int countSegments(string s) {
        bool flag=false;
        int cnt=0;
        for(char ch:s){
            if(ch!=' ' && !flag){
                cnt++;
                flag=true;
            }
            else if(ch==' '){
                flag=false;
            }
        }
        return cnt;
    }
};
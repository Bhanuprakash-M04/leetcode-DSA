class Solution {
public:
    string largestOddNumber(string num) {
        int ind=0;
        bool flag=false;
        for(int i=num.length()-1;i>=0;i--){
            int val=num[i]-'0';
            if(val%2!=0){
                ind=i;
                flag=true;
                break;
            }
        }
        string ans="";
        if(flag){
            for(int i=0;i<=ind;i++){
                ans+=num[i];
            }
        }
        return ans;
    }
};
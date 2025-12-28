class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n=bills.size();
        int f_cnt=0;
        int t_cnt=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                f_cnt++;
            }
            if(bills[i]==10){
                t_cnt++;
                if(f_cnt==0)
                    return false;
                else{
                    f_cnt--;
                }
            }
            if(bills[i]==20){
                if(f_cnt>=1 && t_cnt>=1){
                    f_cnt--;
                    t_cnt--;
                }
                else if(f_cnt>=3){
                    f_cnt-=3;
                }
                else
                    return false;
            }
        }
        return true;
    }
};
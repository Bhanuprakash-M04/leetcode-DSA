class Solution {
public:
    int countDigits(int num) {
        int cnt=0;
        int n=num;
        while(num){
            int val=num%10;
            if(n%val==0)
                cnt++;
            num=num/10;
        }
        return cnt;
    }
};
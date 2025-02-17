class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0))
            return false;
        int reverse_half=0;
        while(x>reverse_half)
        {
            reverse_half=reverse_half*10+(x%10);
            x=x/10;
        }
        if((x==reverse_half) || (x==reverse_half/10))
            return true;
        else
            return false;
    }
};
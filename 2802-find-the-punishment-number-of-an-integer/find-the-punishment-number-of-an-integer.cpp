class Solution {
public:
    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++)
        {
            if(check(i,to_string((i*i)),0))
                sum+=(i*i);
        }
        return sum;
    }
    bool check(int tar,string num,int ind)
    {
        if(ind==num.length())
            return tar==0;
        int sum=0;
        for(int i=ind;i<num.length();i++)
        {
            sum=sum*10+(num[i]-'0');
            if(sum>tar)
                break;
            if(check(tar-sum,num,i+1))
                return true;
        }
        return false;
    }
};
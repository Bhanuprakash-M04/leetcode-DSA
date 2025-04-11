class Solution {
public:
    int num(string s){
        int n=s.length();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=(s[i]-'0');
        }
        return sum;
    }
    int countSymmetricIntegers(int low, int high) {
        int cnt=0;
        for(int i=low;i<=high;i++)
        {
            string x=to_string(i);
            if(x.length()%2!=0)
                continue;
            string a=x.substr(0,x.length()/2);
            string b=x.substr(x.length()/2,x.length());
            //cout << a << " " << b << endl;
            if(num(a)==num(b))
            {
                cnt++;
               // cout << i << endl;
            }
        }
        return cnt;
    }
};
class Solution {
public:
    int check(int x){
        int ans=0;
        while(x){
            ans+=(x%10);
            x=x/10;
        }
        return ans;
    }
    int countLargestGroup(int n) {
        unordered_map<int,int>mymap;
        for(int i=1;i<=n;i++)
        {
            int sum_digits=check(i);
            mymap[sum_digits]++;
        }
        int max_frq=0;
        for(auto x:mymap){
            if(x.second>max_frq)
                max_frq=x.second;
        }
        int cnt=0;
        for(auto x:mymap){
            if(x.second==max_frq)
                cnt++;

        }
        return cnt;
    }
};
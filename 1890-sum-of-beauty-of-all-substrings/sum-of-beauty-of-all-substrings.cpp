class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mymap;
            for(int j=i;j<n;j++){
                int m=0;
                int l=INT_MAX;
                mymap[s[j]]++;
                for(auto i:mymap){
                    m=max(m,i.second);
                    l=min(l,i.second);
                }
                ans+=(m-l);
            }
        }
        return ans;
    }
};
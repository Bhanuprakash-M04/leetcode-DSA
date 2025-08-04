class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int ans=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>mymap;
            multiset<int>myset;
            for(int j=i;j<n;j++){
                if(mymap.find(s[j])!=mymap.end())
                    myset.erase(myset.find(mymap[s[j]]));
                mymap[s[j]]++;
                myset.insert(mymap[s[j]]);

                int lf=*myset.begin();
                int mf=*myset.rbegin();
                ans+=(mf-lf);
            }
        }
        return ans;
    }
};
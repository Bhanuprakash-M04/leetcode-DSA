class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m=t.length();
        unordered_map<int,int>mymap;
        for(int i=0;i<m;i++)
            mymap[t[i]]++;
        int left=0;
        int right=0;
        int cnt=0;
        int minLen=INT_MAX,st_ind=-1;
        while(right<n){
            if(mymap[s[right]]>0)
                cnt++;
            mymap[s[right]]--;
            while(cnt==m){
                if(minLen>right-left+1){
                    minLen=right-left+1;
                    st_ind=left;
                }
                mymap[s[left]]++;
                if(mymap[s[left]]>0)
                    cnt--;
                left++;
            }
            right++;
        }
        return (st_ind==-1) ? "" : s.substr(st_ind,minLen);
    }
};
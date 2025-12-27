class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        unordered_map<int,int>mymap;
        int left=0;
        int maxi=0;
        int ans=0;
        for(int right=0;right<n;right++){
            mymap[s[right]]++;
            maxi=max(maxi,mymap[s[right]]);
            if((right-left+1)-maxi>k){
                mymap[s[left]]--;
                if(mymap[s[left]]==0)
                    mymap.erase(s[left]);
                left++;
            }
            if((right-left+1)-maxi<=k)
                ans=max(ans,(right-left+1));
        }
        return ans;
    }
};
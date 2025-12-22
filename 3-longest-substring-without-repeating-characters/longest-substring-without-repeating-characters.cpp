class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        int left=0;
        unordered_set<int>myset;
        int ans=0;
        for(int right=0;right<n;right++){
            while(myset.find(s[right])!=myset.end()){
                myset.erase(s[left]);
                left++;
            }
            myset.insert(s[right]);
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
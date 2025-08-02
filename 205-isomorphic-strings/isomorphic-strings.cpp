class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>first;
        unordered_map<char,char>second;
        for(int i=0;i<s.length();i++){
            if(first.find(s[i])==first.end()){
                first[s[i]]=t[i];
            }
            if(second.find(t[i])==second.end()){
                second[t[i]]=s[i];
            }
            if(first[s[i]]!=t[i] || second[t[i]]!=s[i])
                return false;
        }
        return true;
    }
};
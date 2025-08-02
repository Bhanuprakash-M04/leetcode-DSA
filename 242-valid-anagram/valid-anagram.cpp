class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int,int>mymap;
        for(int i=0;i<s.length();i++){
            mymap[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            mymap[t[i]]--;
        }
        for(auto i:mymap){
            if(i.second!=0)
                return false;
        }
        return true;
    }
};
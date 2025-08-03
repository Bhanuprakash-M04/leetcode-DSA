class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mymap;
        for(char ch:s){
            mymap[ch]++;
        }
        int max_freq=0;                         //unordered_map+ bucket sort
        for(auto [ch,cnt]:mymap){
            max_freq=max(max_freq,cnt);
        }
        vector<vector<char>>bucket(max_freq+1);
        for(auto [ch,cnt]:mymap){
            bucket[cnt].push_back(ch);
        }
        string ans;
        for(int i=max_freq;i>=1;i--){
            for(char ch:bucket[i]){
                ans.append(i,ch);
            }
        }
        return ans;
    }
};
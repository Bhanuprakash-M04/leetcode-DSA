class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mymap;
        for(char ch:s){
            mymap[ch]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto [ch,cnt]:mymap){
            pq.push({cnt,ch});
        }
        string ans="";
        while(!pq.empty()){
            auto [ch,cnt]=pq.top();
            pq.pop();
            ans.append(ch,cnt);
        }
        return ans;
    }
};
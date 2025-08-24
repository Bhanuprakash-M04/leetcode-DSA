class Solution {
public:
    void generate(int n,string curr,vector<string>& ans){
        if(curr.size()==n){
            ans.push_back(curr);
            return ;
        }
        if(curr.empty() || curr.back()!='0')
            generate(n,curr+'0',ans);
        generate(n,curr+'1',ans);
    }
    vector<string> validStrings(int n) {
        vector<string>ans;
        generate(n,"",ans);
        return ans;
    }
};
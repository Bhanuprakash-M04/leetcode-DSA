class Solution {
public:
    bool ispalindrome(string& s,int start,int end){
        while(start<end){
            if(s[start]!=s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    void generate(string& s,vector<vector<string>>& ans,vector<string>& curr,int ind){
        if(ind==s.length()){
            ans.push_back(curr);
            return ;
        }
        for(int i=ind;i<s.length();i++){
            if(ispalindrome(s,ind,i)){
                string str=s.substr(ind,i-ind+1);
                curr.push_back(str);
                generate(s,ans,curr,i+1);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>curr;
        generate(s,ans,curr,0);
        return ans;
    }
};
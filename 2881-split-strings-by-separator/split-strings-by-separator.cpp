class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string>ans;
        for(string word:words){
            int n=word.length();
            string curr="";
            for(int i=0;i<n;i++){
                if(word[i]!=separator){
                    curr+=word[i];
                }
                else{
                    if(curr!="")
                        ans.push_back(curr);
                    curr="";
                }
            }
            if(curr!="")
                ans.push_back(curr);
        }
        return ans;
    }
};
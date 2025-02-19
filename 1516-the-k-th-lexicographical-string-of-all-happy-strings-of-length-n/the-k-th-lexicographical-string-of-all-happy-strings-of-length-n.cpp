class Solution {
public:
    void generate(int n,string curr,vector<string>& happy)
    {
        if(n==curr.length())
        {
            happy.push_back(curr);
            return;
        }
        for(char ch:{'a','b','c'})
        {
            if(curr.empty() || ch!=curr.back())
            {
                generate(n,curr+ch,happy);
            }
        }
        
    }
    string getHappyString(int n, int k) {
        vector<string>happy;
        generate(n,"",happy);
        if(k>happy.size())
            return "";
        return happy[k-1];
    }
};
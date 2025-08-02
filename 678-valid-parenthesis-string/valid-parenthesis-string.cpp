class Solution {
public:
    bool checkValidString(string s) {
        int open=0;
        int close=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(' || s[i]=='*')
                open++;
            else
                open--;
            if(s[s.length()-i-1]==')' || s[s.length()-i-1]=='*')
                close++;
            else
                close--;

            if(open<0 || close<0)
                return false;
        }
        return true;
    }
};
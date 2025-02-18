class Solution {
public:
    string smallestNumber(string pattern) {
        int n=pattern.length();
        string A;
        int cnt=1;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            if(pattern[i]=='I')
            {
                st.push(cnt);
                cnt++;
                while(!st.empty())
                {
                    A.push_back(st.top()+'0');
                    st.pop();
                }
            }
            else
            {
                st.push(cnt);
                cnt++;
            }
            if(i==n-1)
            {
                st.push(cnt);
            }
        }
        while(!st.empty())
        {
            A.push_back(st.top()+'0');
            st.pop();
        }
        return A;

    }
};
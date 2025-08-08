class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(auto i:asteroids){
            if(i>0 || st.empty())
                st.push(i);
            else{
                if(!st.empty() && st.top()<0 && i<0)
                    st.push(i);
                while(!st.empty() && st.top()>0 && abs(st.top())<=abs(i))
                {
                    if(abs(st.top())==abs(i))
                    {
                        st.pop();
                        break;
                    }
                    else{
                        st.pop();
                        if(st.empty() || st.top()<0)
                        {
                            st.push(i);
                            break;
                        }
                    }
                }
            }
        }
        vector<int>ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
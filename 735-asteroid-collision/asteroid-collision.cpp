class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        for(int num:asteroids){
            if(num>0){
                st.push(num);
            }
            else if(num<0 && (st.empty() || st.top()<0)){
                st.push(num);
            }
            else{
                while(!st.empty() && st.top()>0 && st.top()<-num){
                    st.pop();
                }
                if(!st.empty() && st.top()==-num){
                    st.pop();
                    continue;
                }
                if(st.empty() || st.top()<0)
                    st.push(num);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
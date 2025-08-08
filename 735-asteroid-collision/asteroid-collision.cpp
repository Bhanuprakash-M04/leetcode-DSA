class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        vector<int>ans;
        int n=asteroids.size();
        st.push(asteroids[0]);
        for(int i=1;i<n;i++){
            if(asteroids[i]>0){
                st.push(asteroids[i]);
            }
            else if(st.empty()){
                st.push(asteroids[i]);
            }
            else if(st.top()>0 && asteroids[i]<0){
                int res=asteroids[i];
                while(!st.empty()){
                    int x=st.top();
                    if(abs(x)==abs(res))
                    {
                        st.pop();
                        break;
                    }
                    else{
                        int val=max(abs(x),abs(res));
                        st.pop();
                        if(val==abs(res)){
                            val=-val;
                            res=val;
                            if(!st.empty() && st.top()<0)
                            {
                                st.push(res);
                                break; 
                            }
                            else if(st.empty())
                            {
                                st.push(res);
                                break;
                            }
                        }
                        else{
                            st.push(val);
                            break;
                        }   
                    } 
                }
            }
            else if(st.top()<0 && asteroids[i]<0)
                st.push(asteroids[i]);
    
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
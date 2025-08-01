class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<int>q;
        int n=tickets.size();
        for(int i=0;i<n;i++){
            q.push(i);
        }
        int cnt=0;
        while(!q.empty()){
            if(tickets[q.front()]==0)
            {
                q.pop();
            }
            else{
                tickets[q.front()]--;
                int x=q.front();
                q.pop();
                q.push(x);
                cnt++;
            }
            if(tickets[k]==0)
                return cnt;  
        }
        return 0;
    }
};
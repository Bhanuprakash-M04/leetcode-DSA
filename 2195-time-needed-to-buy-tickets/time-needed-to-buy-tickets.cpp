class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(i<=k){
                ans+=min(tickets[i],tickets[k]);
            }
            else{
                if(tickets[i]>=tickets[k]){
                    ans+=tickets[k]-1;
                }
                else{
                    ans+=tickets[i];
                }
            }
        }
        return ans;
    }
};
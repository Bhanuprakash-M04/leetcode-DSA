class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit=0;
        int n=prices.size();
        int curr=prices[0];
        for(int i=1;i<n;i++)
        {
            if(curr>prices[i])
                curr=prices[i];
            else if(prices[i]-curr>profit)
                profit=prices[i]-curr;
        }
        return profit;
    }
};
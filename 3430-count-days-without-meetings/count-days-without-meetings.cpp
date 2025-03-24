class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        int cnt=0;
        sort(meetings.begin(),meetings.end());
        int last_meet=meetings[0][1];
        int first_meet=meetings[0][0];
        for(int i=1;i<n;i++)
        {
            int st=meetings[i][0];
            int end=meetings[i][1];
            if(st>last_meet)
            {
                cnt+=(st-last_meet)-1;
            }
            first_meet=min(first_meet,st);
            last_meet=max(last_meet,end);
        }
        return (first_meet-1)+cnt+(days-last_meet);
        
    }
};
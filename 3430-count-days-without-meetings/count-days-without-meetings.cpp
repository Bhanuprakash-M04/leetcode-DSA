class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n=meetings.size();
        int cnt=0;
        sort(meetings.begin(),meetings.end());
        for(int i=0;i<n;i++)
        {
            cout << meetings[i][0] << " " << meetings[i][1] << endl;
        }
        int last_meet=meetings[0][1];
        int first_meet=meetings[0][0];
        for(int i=0;i<n-1;i++)
        {
            int st=meetings[i][0];
            int end=meetings[i][1];
            
            int next_st=meetings[i+1][0];
            int next_end=meetings[i+1][1];

           
            
            if(next_st>last_meet)
            {
                cnt+=(next_st-last_meet)-1;
            }
            first_meet=min(first_meet,next_st);
             last_meet=max(last_meet,next_end);
        }
        if(last_meet==days && first_meet==1)
            return cnt;
        else 
            return (first_meet-1)+cnt+(days-last_meet);
        
    }
};
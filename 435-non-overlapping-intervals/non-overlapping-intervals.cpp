class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>>copy;
        for(int i=0;i<n;i++){
            copy.push_back({intervals[i][1],intervals[i][0]});
        }
        sort(copy.begin(),copy.end());
        int time=INT_MIN;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(copy[i][1]>=time){
                cnt++;
                time=copy[i][0];
            }
        }
        return n-cnt;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>>ans;
        sort(interval.begin(),interval.end());
        int n=interval.size();
        vector<int>temp(2);
        int first=interval[0][0];
        int second=interval[0][1];
        temp[0]=first;
        temp[1]=second;
        for(int i=1;i<n;i++){
            if(interval[i][0]<=second){
                second=max(second,interval[i][1]);
                temp[1]=second;
            }
            else{
                ans.push_back(temp);
                first=interval[i][0];
                second=interval[i][1];
                temp[0]=first;
                temp[1]=second;
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
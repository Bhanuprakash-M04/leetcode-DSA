class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& interval) {
        vector<vector<int>>ans;
        sort(interval.begin(),interval.end());
        int n=interval.size();
        vector<int>temp(2);
        temp[0]=interval[0][0];
        temp[1]=interval[0][1];
        for(int i=1;i<n;i++){
            if(interval[i][0]<=temp[1]){
               temp[1]= max(temp[1],interval[i][1]);
            }
            else{
                ans.push_back(temp);
                temp[0]=interval[i][0];
                temp[1]=interval[i][1];
            }
        }
        ans.push_back(temp);
        return ans;
    }
};
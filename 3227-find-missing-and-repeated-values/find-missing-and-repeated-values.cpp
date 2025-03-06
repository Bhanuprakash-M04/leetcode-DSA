class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int>myset;
        int n=grid.size();
        int m=grid[0].size();
        int a=0,b=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(myset.find(grid[i][j])==myset.end())
                    myset.insert(grid[i][j]);
                else
                    a=grid[i][j];
            }
        }
        for(int i=1;i<=n*n;i++)
        {
            if(myset.find(i)==myset.end())
                b=i;
        }
        return {a,b};
    }
};
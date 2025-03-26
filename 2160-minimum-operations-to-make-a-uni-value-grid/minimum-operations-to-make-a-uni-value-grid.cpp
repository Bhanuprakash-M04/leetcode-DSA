class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>arr;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                arr.push_back(grid[i][j]);
            }
        }
        sort(arr.begin(),arr.end());
        int l=arr.size();
        int mid=arr[l/2];
        int cnt=0;
        for(int i=0;i<l-1;i++)
        {
            if(arr[i]%x != arr[i+1]%x)
                return -1;
            int add=abs(arr[i]-mid);
            cnt+=(add/x);
        }
        cnt+=(abs(arr[l-1]-mid)/x);
        return cnt;


    }
};
class Solution {
public:
    void bfs(vector<vector<char>>& grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        q.push({i,j});
        while(!q.empty())
        {
            auto [x,y]=q.front();
            q.pop();
            if(x<0 || x>=n || y<0 || y>=m || grid[x][y]=='0')
                continue;
            grid[x][y]='0';
            q.push({x,y+1});
            q.push({x,y-1});
            q.push({x+1,y});
            q.push({x-1,y});
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int islands=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    islands++;
                    bfs(grid,i,j);
                }
            }
        }
        return islands;
    }
};
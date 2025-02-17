class Solution {
public:
    int numTilePossibilities(string tiles) {
        sort(tiles.begin(),tiles.end());
        vector<bool>st(tiles.size(),false);
        return sol(tiles,st);
    }
    int sol(string& tiles, vector<bool>& st)
    {
        int ans=0;
        for(int i=0;i<tiles.size();i++)
        {
            if((i>0 && tiles[i]==tiles[i-1] && !st[i-1]) || st[i])
                continue;
            st[i]=true;
            ans+=1+sol(tiles,st);
            st[i]=false;
        }
        return ans;
    }
};
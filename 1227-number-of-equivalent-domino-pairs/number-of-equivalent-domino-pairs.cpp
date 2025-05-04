class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int n=dominoes.size();
        int cnt=0;
        map<pair<int,int>,int>mymap;
        for(int i=0;i<n;i++)
        {
            if(mymap.find({dominoes[i][0],dominoes[i][1]})!=mymap.end())
                cnt+=mymap[{dominoes[i][0],dominoes[i][1]}];
            if(dominoes[i][0]==dominoes[i][1])
                mymap[{dominoes[i][0],dominoes[i][1]}]++;
            else{
            mymap[{dominoes[i][0],dominoes[i][1]}]++;
            mymap[{dominoes[i][1],dominoes[i][0]}]++;
            }
        }
        return cnt;
    }
};
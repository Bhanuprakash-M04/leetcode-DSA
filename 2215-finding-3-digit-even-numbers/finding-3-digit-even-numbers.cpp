class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int>ans;
        int freq[10]={0};
        for(auto i:digits)
            freq[i]++;
        for(int i=100;i<=999;i++)
        {
            if(i%2==0)
            {
                string s=to_string(i);
                int x=s[0]-'0';
                int y=s[1]-'0';
                int z=s[2]-'0';
                int valFreq[10]={0};
                valFreq[x]++;
                valFreq[y]++;
                valFreq[z]++;

                bool valid=true;
                for(int d=0;d<10;d++)
                {
                    if(freq[d]<valFreq[d])
                    {
                        valid=false;
                        break;
                    }
                }
                if(valid)
                    ans.push_back(i);
            }
        }
        return ans;
    }
};
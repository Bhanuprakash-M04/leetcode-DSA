class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mymap;
        int n=fruits.size();
        int left=0;
        int ans=0;
        for(int right=0;right<n;right++){
            mymap[fruits[right]]++;
            while(mymap.size()>2){
                mymap[fruits[left]]--;
                if(mymap[fruits[left]]==0)
                    mymap.erase(fruits[left]);
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
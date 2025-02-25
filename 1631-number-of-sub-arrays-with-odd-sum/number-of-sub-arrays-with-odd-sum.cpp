class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
       int mod=1e9+7;
       int odd=0,even=1;
       int result=0;
       int pre=0;
       for(int num:arr)
       {
            pre+=num;
            if(pre%2==0)
            {
                result=(result+odd)%mod;
                even++;
            }
            else
            {
                result=(result+even)%mod;
                odd++;
            }
       }
       return result;

    }
};
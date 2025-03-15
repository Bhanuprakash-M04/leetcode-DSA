class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ans = 0 ;
        int increase = 0 , decrease = 0 ;
        for (int i = 1 ; i < arr.size() ; i++) {
            if ((decrease && arr[i-1] < arr[i]) || arr[i-1] == arr[i])
                increase = decrease = 0 ;

            increase += (arr[i-1] < arr[i]);
            decrease += (arr[i-1] > arr[i]);

            if (increase != 0 && decrease != 0)
                ans = max(ans , increase + decrease + 1 );
        }
        return ans; 
    }
};
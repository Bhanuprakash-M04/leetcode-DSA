class Solution {
public:
    int values(vector<vector<int>>& matrix,int mid){
        int cnt=0;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]<=mid)
                    cnt++;
            }
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int low=matrix[0][0];
        int high=matrix[n-1][n-1];
        while(low<=high){
            int mid=(low+high)/2;
            if(values(matrix,mid)>=k)
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
};
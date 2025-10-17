class Solution {
public:
    int get_max(vector<vector<int>>& mat,int n,int mid){
        int index=-1;
        int maxi=-1;
        for(int i=0;i<n;i++){
            if(maxi<mat[i][mid]){
                maxi=mat[i][mid];
                index=i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        int low=0;
        int high=m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int row_num=get_max(mat,n,mid);
            int left= (mid-1>=0) ? mat[row_num][mid-1] : -1;
            int right =(mid+1<m) ? mat[row_num][mid+1] : -1;
            if(mat[row_num][mid]>left && mat[row_num][mid]>right)
                return {row_num,mid};
            else if(mat[row_num][mid]<left)
                high=mid-1;
            else
                low=mid+1;
        }
        return {-1,-1};
    }
};
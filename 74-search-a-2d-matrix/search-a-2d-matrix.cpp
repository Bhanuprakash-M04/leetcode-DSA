class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();
        int low=0;
        int high=(n*m)-1;
        while(low<=high){
            int mid=(low+high)/2;
            // think like converting the 2d matrix into a 1d array
            //converting 1d coordinate into 2d coordinate
            int row=mid/m;
            int col=mid%m;
            if(matrix[row][col]==target)
                return true;
            else if(matrix[row][col]>target)
                high=mid-1;
            else
                low=mid+1;
        }
        return false;
    }
};
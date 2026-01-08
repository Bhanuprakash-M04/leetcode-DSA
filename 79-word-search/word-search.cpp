class Solution {
public:
    bool check(vector<vector<char>>& board, string word,int i,int j,int ind,int n,int m){
        if(ind==word.length())
            return true;
        if(i<0 || j<0 || i>=n || j>=m || board[i][j]!=word[ind])
            return false;
        char ch=board[i][j];
        board[i][j]='@';
        bool flag=check(board,word,i,j+1,ind+1,n,m) || check(board,word,i+1,j,ind+1,n,m) || check(board,word,i-1,j,ind+1,n,m) || check(board,word,i,j-1,ind+1,n,m);
        board[i][j]=ch;
        return flag;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(check(board,word,i,j,0,n,m))
                    return true;
            }
        }
        return false;
    }
};
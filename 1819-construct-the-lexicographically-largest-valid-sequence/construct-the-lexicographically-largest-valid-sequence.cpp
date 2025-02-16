class Solution {
public:
    int x;
    vector<int> result;
    void backtrack(int ind, vector<int>& a, vector<int>& sol) {
        if (result[0]!=0) {
            return;
        }
        if (ind>=a.size()) {
            result=a;
            return;
        }
        if (a[ind]!=0) {
            backtrack(ind+1,a,sol);
            return;
        }
        for (int i = x;i>=1;i--) {
            if (a[ind]==0&&i==1&&sol[i]!=0) {
                sol[i]=0;
                a[ind]=i;
                backtrack(ind+1,a,sol);
                a[ind]=0;
                sol[i]=1;
            }
            else if (a[ind]==0&&ind+i<a.size()&&a[ind+i]==0&&sol[i]!=0) {
                a[ind]=i;
                a[ind+i]=i;
                sol[i]=0;
                backtrack(ind+1,a,sol);
                a[ind]=0;
                a[ind+i]=0;
                sol[i]=1;
            }
        }
    }
    vector<int> constructDistancedSequence(int n) {
        result= vector<int>((n*2)-1);
        vector<int>ans((n*2)-1);
        x=n;
        vector<int>sol(n+1,1);
        backtrack(0,ans,sol);
        return result;
    }
};
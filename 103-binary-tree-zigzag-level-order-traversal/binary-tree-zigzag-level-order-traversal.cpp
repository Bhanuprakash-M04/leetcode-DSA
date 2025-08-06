/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ans;
        if(root!=NULL)
            q.push(root);
        bool flag=true;
        while(!q.empty()){
            vector<int>res;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* tmp=q.front();
                res.push_back(tmp->val);
                if(tmp->left!=NULL)
                    q.push(tmp->left);
                if(tmp->right!=NULL)
                    q.push(tmp->right);
                q.pop();
            }
            if(flag==true){
                ans.push_back(res);
                flag=false;
            }
            else{
                reverse(res.begin(),res.end());
                ans.push_back(res);
                flag=true;
            }   
        }
        return ans;
    }
};
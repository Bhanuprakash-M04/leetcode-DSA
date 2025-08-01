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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        if(root!=NULL)
            q.push(root);
        vector<vector<int>>ans;
        while(!q.empty()){
            vector<int>pro;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* tmp=q.front();
                if(tmp->left)
                    q.push(tmp->left);
                if(tmp->right)
                    q.push(tmp->right);
                q.pop();
                pro.push_back(tmp->val);
            }
            ans.push_back(pro);
        }
        return ans;
    }
};
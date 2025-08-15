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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* tmp=root;
        TreeNode* nn=new TreeNode(val);
        if(root==NULL)
            return nn;
        while(root!=NULL){
            if(root->val>val)
            {
                if(root->left!=NULL)
                    root=root->left;
                else
                {
                    root->left=nn;
                    break;
                }
            }
            else
            {
                if(root->right!=NULL)
                    root=root->right;
                else
                {
                    root->right=nn;
                    break;
                }
            }
                
        }
        return tmp;
    }
};
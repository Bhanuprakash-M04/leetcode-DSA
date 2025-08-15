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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode* tmp=root;
        if(root==NULL)
            return root;
        if(root->val==key)
            return helper(root);
        while(root!=NULL){
            if(root->val>key){
                if(root->left!=NULL && root->left->val==key)
                {
                    root->left=helper(root->left);
                    break;
                }
                else
                    root=root->left;
            }
            else{
                if(root->right!=NULL && root->right->val==key){
                    root->right=helper(root->right);
                    break;
                }
                else
                    root=root->right;
            }
        }
        return tmp;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left==NULL && root->right==NULL)
            return NULL;
        if(root->left==NULL)
            return root->right;
        if(root->right==NULL)
            return root->left;
        TreeNode* right_child=root->right;
        TreeNode* left_max=leftMax(root->left);
        left_max->right=right_child;
        return root->left;
    }
    TreeNode* leftMax(TreeNode* root){
        if(root->right==NULL)
            return root;
        return leftMax(root->right);
    }
};
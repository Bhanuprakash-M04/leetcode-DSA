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
    int preind=0,posind=0;
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root=new TreeNode(preorder[preind++]);
        if(root->val!=postorder[posind])
            root->left=constructFromPrePost(preorder,postorder);
        if(root->val!=postorder[posind])
            root->right=constructFromPrePost(preorder,postorder);
        posind++;
        return root;
    }
};
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
    bool isSymmetric(TreeNode* root) {
        return (root==NULL) || (check(root->left,root->right));
    }
    bool check(TreeNode* Left,TreeNode* Right){
        if(Left==NULL || Right==NULL)
            return Left==Right;
        if(Left->val!=Right->val)
            return false;
        return (check(Left->left,Right->right) && (check(Left->right,Right->left)));
    }
};
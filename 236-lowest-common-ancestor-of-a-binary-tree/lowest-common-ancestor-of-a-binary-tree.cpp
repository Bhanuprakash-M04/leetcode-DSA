/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findPath(TreeNode* root,TreeNode* node,vector<TreeNode*>& res){
        if(root==NULL)
            return false;
        res.push_back(root);
        if(root->val==node->val)
            return true;
        if(findPath(root->left,node,res) || findPath(root->right,node,res))
            return true;
        res.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*>first;
        vector<TreeNode*>second;
        findPath(root,p,first);
        findPath(root,q,second);
        int n=min(first.size(),second.size());
        TreeNode* ans=NULL;
        for(int i=0;i<n;i++)
        {
            if(first[i]->val==second[i]->val)
                ans=first[i];
        }
        return ans;
    }

};
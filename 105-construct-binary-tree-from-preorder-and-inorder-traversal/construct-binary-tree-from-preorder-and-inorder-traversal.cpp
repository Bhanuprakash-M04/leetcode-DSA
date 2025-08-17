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
    TreeNode* construct(vector<int>&preorder,int pre_start,int pre_end,vector<int>&inorder,int in_start,int in_end,unordered_map<int,int>&mymap){
        if(pre_start>pre_end || in_start>in_end)
            return NULL;
        TreeNode* root=new TreeNode(preorder[pre_start]);
        int in_root=mymap[root->val];
        int nums_left=in_root-in_start;
        root->left=construct(preorder,pre_start+1,pre_end+nums_left,inorder,in_start,in_root-1,mymap);
        root->right=construct(preorder,pre_start+nums_left+1,pre_end,inorder,in_root+1,in_end,mymap);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mymap;
        for(int i=0;i<inorder.size();i++){
            mymap[inorder[i]]=i;
        }
        return construct(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,mymap);
    }
};
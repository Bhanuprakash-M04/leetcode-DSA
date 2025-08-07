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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        if(root==NULL)
            return ans;
        queue<pair<TreeNode*,int>>q;
        map<int,int>mymap;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* tmp=q.front().first;
            int value=q.front().second;
            mymap[value]=tmp->val;
            q.pop();
            if(tmp->left!=NULL)
                q.push({tmp->left,value+1});
            if(tmp->right!=NULL)
                q.push({tmp->right,value+1});
        }
        for(auto it:mymap){
            ans.push_back(it.second);
        }
        return ans;
    }
};
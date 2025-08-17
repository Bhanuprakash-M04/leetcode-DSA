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
    void trackParent(unordered_map<TreeNode*,TreeNode*>& parent,TreeNode* root){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp=q.front();
            q.pop();
            if(tmp->left){
                q.push(tmp->left);
                parent[tmp->left]=tmp;
            }
            if(tmp->right){
                q.push(tmp->right);
                parent[tmp->right]=tmp;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent;
        trackParent(parent,root);
        queue<TreeNode*>q;
        unordered_map<TreeNode*,bool>visited;
        q.push(target);
        visited[target]=true;
        int cur_lev=0;
        while(!q.empty()){
            int n=q.size();
            if(cur_lev==k)
                break;
            cur_lev++;
            for(int i=0;i<n;i++){
                TreeNode* tmp=q.front();
                q.pop();
                if(parent[tmp] && !visited[parent[tmp]])
                {
                    q.push(parent[tmp]);
                    visited[parent[tmp]]=true;
                }
                if(tmp->left && !visited[tmp->left])
                {
                    q.push(tmp->left);
                    visited[tmp->left]=true;
                }
                if(tmp->right && !visited[tmp->right])
                {
                    q.push(tmp->right);
                    visited[tmp->right]=true;
                }
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};
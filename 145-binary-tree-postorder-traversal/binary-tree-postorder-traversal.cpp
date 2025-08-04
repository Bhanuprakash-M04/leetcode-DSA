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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        TreeNode* curr=root;
        while(curr!=NULL || !st.empty()){
            if(curr!=NULL){
                st.push(curr);
                curr=curr->left;
            }
            else{
                TreeNode* tmp=st.top()->right;
                if(tmp==NULL){
                    tmp=st.top();
                    st.pop();
                    ans.push_back(tmp->val);
                    while(!st.empty() && st.top()->right==tmp){
                        tmp=st.top();
                        st.pop();
                        ans.push_back(tmp->val);
                    }
                }
                else{
                    curr=tmp;
                }
            }
        }
        return ans;
    }
};
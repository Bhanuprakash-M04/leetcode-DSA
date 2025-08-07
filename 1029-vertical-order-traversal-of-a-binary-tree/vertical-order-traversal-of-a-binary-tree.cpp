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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        map<int,map<int,map<int,int>>>mymap;
        vertical(root,0,0,mymap);
        for(auto i:mymap){
            vector<int>res;
            for(auto j:i.second){
                for(auto k:j.second){
                    int freq=k.second;
                    while(freq--){
                        res.push_back(k.first);
                    }
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
    void vertical(TreeNode* root,int h_lev,int v_lev,map<int,map<int,map<int,int>>>&mymap){
        if(root==NULL)
            return;
        mymap[v_lev][h_lev][root->val]++;
        vertical(root->left,h_lev+1,v_lev-1,mymap);
        vertical(root->right,h_lev+1,v_lev+1,mymap);
    }
};
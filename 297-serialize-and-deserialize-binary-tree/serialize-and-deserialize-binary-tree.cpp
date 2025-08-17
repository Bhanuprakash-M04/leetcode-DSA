/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        queue<TreeNode*>q;
        if(root==NULL)
            return ans;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp=q.front();
            q.pop();
            if(tmp){
                ans=ans+to_string(tmp->val)+",";
                q.push(tmp->left);
                q.push(tmp->right);
            }
            else{
                ans=ans+"#,";
            }
        }
        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0)
            return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* tmp=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="#")
                tmp->left=NULL;
            else
            {
                tmp->left=new TreeNode(stoi(str));
                q.push(tmp->left);
            }
            getline(s,str,',');
            if(str=="#")
                tmp->right=NULL;
            else
            {
                tmp->right=new TreeNode(stoi(str));
                q.push(tmp->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
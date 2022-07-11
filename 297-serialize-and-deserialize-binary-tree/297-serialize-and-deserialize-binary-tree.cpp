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

    
    string serialize(TreeNode* root) 
    {
        if(!root) {
            return "NULL,";
        }
        return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
    }


    //Decodes your encoded data to tree.
    TreeNode*helper(queue<string>&q)
    {
        string nodeVal=q.front();
        q.pop();
        if(nodeVal=="NULL")
            return NULL;

        TreeNode*root=new TreeNode(stoi(nodeVal));
        root->left=helper(q);
        root->right=helper(q);
        return root;
          
    }

    TreeNode* deserialize(string data) 
    {
        queue<string>q;
        stringstream s(data);
        string nodeVal;
        while(getline(s,nodeVal,',')){
            q.push(nodeVal);
        }
        return helper(q);
    }
    
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
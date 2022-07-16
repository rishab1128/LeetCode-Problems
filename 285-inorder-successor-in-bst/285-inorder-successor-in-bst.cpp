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
    TreeNode*ans;
    
    void dfs(TreeNode*root, TreeNode*node, TreeNode*p)
    {
        if(!root){
            ans = node;
            return;
        }
        if(root->val<=p->val)
            dfs(root->right,node,p);
        else
            dfs(root->left,root,p);
    }
    
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        ans = NULL;
        dfs(root,NULL,p);
        return ans;
    }
};
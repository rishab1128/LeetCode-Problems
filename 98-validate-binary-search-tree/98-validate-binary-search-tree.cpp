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
    
    bool inorder(TreeNode*root, TreeNode*&prev)
    {
        if(!root)
            return true;
        
        bool lt = inorder(root->left,prev);
        
        if(prev and prev->val>=root->val)
            return false;
                
        prev = root;
        
        bool rt = inorder(root->right,prev);
        
        return lt and rt;
    }
    
    bool isValidBST(TreeNode* root) 
    {
        TreeNode*prev = NULL;
        return inorder(root,prev);
    }
};
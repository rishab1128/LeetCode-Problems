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
    TreeNode* recur(TreeNode*root)
    {
        if(!root)
            return NULL;
        
         
        TreeNode* lt = recur(root->left);
        TreeNode* rt = recur(root->right);
        
        if(lt)
        {
            TreeNode*tmp = lt;
            while(tmp and tmp->right!=NULL)
                tmp = tmp->right;
        
            tmp->right = rt;
            
            root->right = lt;
            root->left  = NULL;
        }
    
        return root;    
    }
    
    void flatten(TreeNode* root) 
    {
        root = recur(root);
        return;
    }
};
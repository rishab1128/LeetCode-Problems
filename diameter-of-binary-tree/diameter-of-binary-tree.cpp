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
    
    int height(TreeNode*root)
    {
        if(!root)
            return 0;
        return max(height(root->left) , height(root->right))+1;
    }
    
    int diameter(TreeNode*root)
    {
        if(!root)
            return 0;
        
        int f=height(root->left)+height(root->right); //max-dist b/w a node in lhs and a node in rhs
        int ld=diameter(root->left); //max-dist b/w two nodes in lhs
        int rd=diameter(root->right); //max-dist b/w two nodes in rhs
        
        int dia=max({ld,rd,f});
        
        return dia;
    }
    
    int diameterOfBinaryTree(TreeNode* root) 
    {
        return diameter(root);
    }
};
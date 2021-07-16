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
    bool checkIdentical(TreeNode* root, TreeNode* subRoot)
    {
        if(!root and !subRoot)
            return true;
        if((root and !subRoot)||(!root and subRoot)||(root and subRoot and root->val!=subRoot->val))
            return false;
        return checkIdentical(root->left,subRoot->left) and checkIdentical(root->right , subRoot->right);
            
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) 
    {
        
        if((root and !subRoot)||(!root and subRoot))
            return false;
        
        if(checkIdentical(root,subRoot))
            return true;
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
        
    }
};
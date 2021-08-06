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
    int pathSum(TreeNode* root, int target) 
    {
        if(!root)
            return 0;
        
        return dfs(root,0,target)+pathSum(root->left,target)+pathSum(root->right,target);
        
    }
    int dfs(TreeNode*root , int curr , int&target)
    {
        if(!root)
            return 0;
        curr+=root->val;
        return ((curr==target) ? 1 : 0)+dfs(root->left,curr,target)+dfs(root->right,curr,target);
    }
};
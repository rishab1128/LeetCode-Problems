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
    int ans;
    void dfs(TreeNode*root , int direction)
    {
        if(!root)
            return;
        if(!root->left and !root->right and direction==1)
        {
            ans+=root->val;
            return;
        }
        dfs(root->left,1);
        dfs(root->right,0);
    }
    
    int sumOfLeftLeaves(TreeNode* root) 
    {
        ans=0;
        dfs(root,-1);
        return ans;
    }
};